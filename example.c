#include <stdio.h>
#include <stdlib.h>
#include "taku_config.h"

int main() {
    // Create a new Taku configuration
    taku_config_t *config = taku_config_create();
    if (!config) {
        fprintf(stderr, "Failed to create configuration\n");
        return 1;
    }
    
    // Print some configuration details
    printf("=== Taku Configuration ===\n");
    printf("Project Name: %s\n", config->general->name);
    printf("Author: %s\n", config->general->author);
    printf("Group: %s\n", config->general->group);
    printf("License: %s\n", config->general->license);
    
    printf("\n=== Frontend Configuration ===\n");
    printf("Type: %s\n", config->frontend->type);
    printf("Build Command: %s\n", config->frontend->build_command);
    printf("Development Mode - Debug: %s\n", 
           config->frontend->flags.development->debug ? "true" : "false");
    printf("Development Mode - Hot Reload: %s\n", 
           config->frontend->flags.development->hot_reload ? "true" : "false");
    
    printf("\n=== Backend Configuration ===\n");
    printf("Type: %s\n", config->backend->type);
    printf("Build Command: %s\n", config->backend->build_command);
    printf("Feature Flags Default: %s\n", 
           config->backend->feature_flags->default_flag ? "true" : "false");
    
    printf("\n=== Terminal Configuration ===\n");
    printf("Type: %s\n", config->terminal->type);
    printf("Config File: %s\n", config->terminal->config_file);
    printf("Plugins:\n");
    for (size_t i = 0; i < config->terminal->plugins_count; i++) {
        printf("  - %s\n", config->terminal->plugins[i]);
    }
    printf("Alias 'l': %s\n", config->terminal->aliases.l);
    
    printf("\n=== Dependencies ===\n");
    printf("Shell - jq: %s\n", config->dependencies->sh->jq);
    printf("C - gcc: %s\n", config->dependencies->c->gcc);
    printf("C - make: %s\n", config->dependencies->c->make);
    printf("C - node: %s\n", config->dependencies->c->node);
    printf("JavaScript - consola: %s\n", config->dependencies->js->consola);
    
    printf("\n=== Documentation ===\n");
    printf("README: %s\n", config->documentation->readme);
    printf("Changelog: %s\n", config->documentation->changelog);
    printf("Contributing: %s\n", config->documentation->contributing);
    printf("License: %s\n", config->documentation->license);
    
    // Validate configuration
    if (taku_config_validate(config)) {
        printf("\n✓ Configuration is valid\n");
    } else {
        printf("\n✗ Configuration is invalid\n");
    }
    
    // Test utility functions
    char *project_path = taku_config_get_project_path(config);
    if (project_path) {
        printf("Project Path: %s\n", project_path);
        free(project_path);
    }
    
    char *frontend_build_cmd = taku_config_get_build_command(config, "frontend");
    if (frontend_build_cmd) {
        printf("Frontend Build Command: %s\n", frontend_build_cmd);
        free(frontend_build_cmd);
    }
    
    char *backend_build_cmd = taku_config_get_build_command(config, "backend");
    if (backend_build_cmd) {
        printf("Backend Build Command: %s\n", backend_build_cmd);
        free(backend_build_cmd);
    }
    
    printf("Development Mode: %s\n", 
           taku_config_is_development_mode(config) ? "true" : "false");
    
    // Clean up
    taku_config_destroy(config);
    
    printf("\n=== Configuration destroyed successfully ===\n");
    
    return 0;
}
