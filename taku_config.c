#include "taku_config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to duplicate strings safely
static char *safe_strdup(const char *str) {
    if (!str) return NULL;
    size_t len = strlen(str) + 1;
    char *copy = malloc(len);
    if (copy) {
        memcpy(copy, str, len);
    }
    return copy;
}

// Helper function to free string arrays
static void free_string_array(char **array, size_t count) {
    if (!array) return;
    for (size_t i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}

// Environment config functions
static env_config_t *env_config_create(const char *node_env, const char *api_url, const char *analytics_id) {
    env_config_t *env = malloc(sizeof(env_config_t));
    if (!env) return NULL;
    
    env->node_env = safe_strdup(node_env);
    env->api_url = safe_strdup(api_url);
    env->analytics_id = safe_strdup(analytics_id);
    
    return env;
}

static void env_config_destroy(env_config_t *env) {
    if (!env) return;
    free(env->node_env);
    free(env->api_url);
    free(env->analytics_id);
    free(env);
}

// Flags config functions
static flags_config_t *flags_config_create(bool debug, bool hot_reload, bool source_maps, env_config_t *env) {
    flags_config_t *flags = malloc(sizeof(flags_config_t));
    if (!flags) return NULL;
    
    flags->debug = debug;
    flags->hot_reload = hot_reload;
    flags->source_maps = source_maps;
    flags->env = env;
    
    return flags;
}

static void flags_config_destroy(flags_config_t *flags) {
    if (!flags) return;
    env_config_destroy(flags->env);
    free(flags);
}

// Phone config functions
static phone_config_t *phone_config_create(const char *country_code, const char *number) {
    phone_config_t *phone = malloc(sizeof(phone_config_t));
    if (!phone) return NULL;
    
    phone->country_code = safe_strdup(country_code);
    phone->number = safe_strdup(number);
    
    return phone;
}

static void phone_config_destroy(phone_config_t *phone) {
    if (!phone) return;
    free(phone->country_code);
    free(phone->number);
    free(phone);
}

// General config functions
general_config_t *general_config_create(const char *name, const char *author, const char *group, const char *license) {
    general_config_t *config = malloc(sizeof(general_config_t));
    if (!config) return NULL;
    
    config->name = safe_strdup(name);
    config->author = safe_strdup(author);
    config->group = safe_strdup(group);
    config->license = safe_strdup(license);
    
    return config;
}

void general_config_destroy(general_config_t *config) {
    if (!config) return;
    free(config->name);
    free(config->author);
    free(config->group);
    free(config->license);
    free(config);
}

// Support config functions
support_config_t *support_config_create(const char *email, const char *url, const char *country_code, const char *number) {
    support_config_t *config = malloc(sizeof(support_config_t));
    if (!config) return NULL;
    
    config->email = safe_strdup(email);
    config->url = safe_strdup(url);
    config->phone = phone_config_create(country_code, number);
    
    return config;
}

void support_config_destroy(support_config_t *config) {
    if (!config) return;
    free(config->email);
    free(config->url);
    phone_config_destroy(config->phone);
    free(config);
}

// Version control config functions
version_control_config_t *version_control_config_create(const char *system, const char *repository, const char *branch) {
    version_control_config_t *config = malloc(sizeof(version_control_config_t));
    if (!config) return NULL;
    
    config->system = safe_strdup(system);
    config->repository = safe_strdup(repository);
    config->branch = safe_strdup(branch);
    config->issues = NULL; // Initialize as NULL, can be set later
    
    return config;
}

void version_control_config_destroy(version_control_config_t *config) {
    if (!config) return;
    free(config->system);
    free(config->repository);
    free(config->branch);
    if (config->issues) {
        free(config->issues->url);
        free(config->issues->template);
        free_string_array(config->issues->labels, config->issues->labels_count);
        free(config->issues);
    }
    free(config);
}

// Frontend config functions
frontend_config_t *frontend_config_create(const char *type, const char *build_command) {
    frontend_config_t *config = malloc(sizeof(frontend_config_t));
    if (!config) return NULL;
    
    config->type = safe_strdup(type);
    config->build_command = safe_strdup(build_command);
    
    // Initialize flags with default values
    env_config_t *dev_env = env_config_create("development", "https://api.example.com", "UA-12345678-1");
    env_config_t *prod_env = env_config_create("production", "https://api.example.com", "UA-12345678-1");
    env_config_t *test_env = env_config_create("test", "https://test-api.example.com", NULL);
    
    config->flags.development = flags_config_create(true, true, true, dev_env);
    config->flags.production = flags_config_create(false, false, false, prod_env);
    config->flags.testing = flags_config_create(true, true, true, test_env);
    
    return config;
}

void frontend_config_destroy(frontend_config_t *config) {
    if (!config) return;
    free(config->type);
    free(config->build_command);
    flags_config_destroy(config->flags.development);
    flags_config_destroy(config->flags.production);
    flags_config_destroy(config->flags.testing);
    free(config);
}

// Backend config functions
backend_config_t *backend_config_create(const char *type, const char *build_command) {
    backend_config_t *config = malloc(sizeof(backend_config_t));
    if (!config) return NULL;
    
    config->type = safe_strdup(type);
    config->build_command = safe_strdup(build_command);
    
    config->feature_flags = malloc(sizeof(feature_flags_config_t));
    if (config->feature_flags) {
        config->feature_flags->default_flag = true;
    }
    
    return config;
}

void backend_config_destroy(backend_config_t *config) {
    if (!config) return;
    free(config->type);
    free(config->build_command);
    free(config->feature_flags);
    free(config);
}

// Terminal config functions
terminal_config_t *terminal_config_create(const char *type, const char *config_file) {
    terminal_config_t *config = malloc(sizeof(terminal_config_t));
    if (!config) return NULL;
    
    config->type = safe_strdup(type);
    config->config_file = safe_strdup(config_file);
    
    // Initialize with default plugins
    config->plugins_count = 8;
    config->plugins = malloc(sizeof(char*) * config->plugins_count);
    if (config->plugins) {
        config->plugins[0] = safe_strdup("zsh-autosuggestions");
        config->plugins[1] = safe_strdup("zsh-syntax-highlighting");
        config->plugins[2] = safe_strdup("zsh-completions");
        config->plugins[3] = safe_strdup("zsh-history-substring-search");
        config->plugins[4] = safe_strdup("zsh-nvm");
        config->plugins[5] = safe_strdup("zsh-vi-mode");
        config->plugins[6] = safe_strdup("zsh-async");
        config->plugins[7] = safe_strdup("zsh-plugins");
    }
    
    config->aliases.l = safe_strdup("ls -la");
    config->env = env_config_create("development", "https://api.example.com", "UA-12345678-1");
    
    return config;
}

void terminal_config_destroy(terminal_config_t *config) {
    if (!config) return;
    free(config->type);
    free(config->config_file);
    free_string_array(config->plugins, config->plugins_count);
    free(config->aliases.l);
    env_config_destroy(config->env);
    free(config);
}

// Documentation config functions
documentation_config_t *documentation_config_create(void) {
    documentation_config_t *config = malloc(sizeof(documentation_config_t));
    if (!config) return NULL;
    
    // Initialize all documentation fields to NULL
    memset(config, 0, sizeof(documentation_config_t));
    
    // Set default values for common documentation files
    config->readme = safe_strdup("README.md");
    config->changelog = safe_strdup("CHANGELOG.md");
    config->contributing = safe_strdup("CONTRIBUTING.md");
    config->license = safe_strdup("LICENSE");
    
    return config;
}

void documentation_config_destroy(documentation_config_t *config) {
    if (!config) return;
    
    // Free all documentation fields
    free(config->readme);
    free(config->changelog);
    free(config->contributing);
    free(config->license);
    free(config->code_of_conduct);
    free(config->api_reference);
    // ... (would need to free all other fields)
    
    free(config);
}

// Dependencies config functions
dependencies_config_t *dependencies_config_create(void) {
    dependencies_config_t *config = malloc(sizeof(dependencies_config_t));
    if (!config) return NULL;
    
    // Initialize shell dependencies
    config->sh = malloc(sizeof(shell_deps_t));
    if (config->sh) {
        config->sh->jq = safe_strdup("1.8.1");
    }
    
    // Initialize C dependencies
    config->c = malloc(sizeof(c_deps_t));
    if (config->c) {
        config->c->gcc = safe_strdup("9.x");
        config->c->make = safe_strdup("3.81");
        config->c->node = safe_strdup("24.3.0");
    }
    
    // Initialize JavaScript dependencies
    config->js = malloc(sizeof(js_deps_t));
    if (config->js) {
        config->js->consola = safe_strdup("3.4.2");
    }
    
    return config;
}

void dependencies_config_destroy(dependencies_config_t *config) {
    if (!config) return;
    
    if (config->sh) {
        free(config->sh->jq);
        free(config->sh);
    }
    
    if (config->c) {
        free(config->c->gcc);
        free(config->c->make);
        free(config->c->node);
        free(config->c);
    }
    
    if (config->js) {
        free(config->js->consola);
        free(config->js);
    }
    
    free(config);
}

// Main config functions
taku_config_t *taku_config_create(void) {
    taku_config_t *config = malloc(sizeof(taku_config_t));
    if (!config) return NULL;
    
    // Initialize with default values
    config->general = general_config_create("init", "Donald Moore", "imgnx", "0BSD");
    config->support = support_config_create("support@example.com", "https://example.com/support", "+1", "123-456-7890");
    config->version_control = version_control_config_create("git", "https://github.com/username/repo.git", "main");
    config->frontend = frontend_config_create("react", "yarn build");
    config->backend = backend_config_create("rust", "cargo build --release");
    config->terminal = terminal_config_create("zsh", ".zshrc");
    config->documentation = documentation_config_create();
    config->dependencies = dependencies_config_create();
    
    return config;
}

void taku_config_destroy(taku_config_t *config) {
    if (!config) return;
    
    general_config_destroy(config->general);
    support_config_destroy(config->support);
    version_control_config_destroy(config->version_control);
    frontend_config_destroy(config->frontend);
    backend_config_destroy(config->backend);
    terminal_config_destroy(config->terminal);
    documentation_config_destroy(config->documentation);
    dependencies_config_destroy(config->dependencies);
    
    free(config);
}

// Configuration validation
bool taku_config_validate(const taku_config_t *config) {
    if (!config) return false;
    
    // Check required fields
    if (!config->general || !config->general->name || !config->general->author) {
        return false;
    }
    
    if (!config->frontend || !config->frontend->type) {
        return false;
    }
    
    if (!config->backend || !config->backend->type) {
        return false;
    }
    
    return true;
}

// Utility functions
char *taku_config_get_project_path(const taku_config_t *config) {
    if (!config || !config->general || !config->general->name) {
        return NULL;
    }
    
    // Simple implementation - just return the project name
    return safe_strdup(config->general->name);
}

char *taku_config_get_build_command(const taku_config_t *config, const char *target) {
    if (!config || !target) return NULL;
    
    if (strcmp(target, "frontend") == 0 && config->frontend) {
        return safe_strdup(config->frontend->build_command);
    }
    
    if (strcmp(target, "backend") == 0 && config->backend) {
        return safe_strdup(config->backend->build_command);
    }
    
    return NULL;
}

bool taku_config_is_development_mode(const taku_config_t *config) {
    if (!config || !config->frontend || !config->frontend->flags.development) {
        return false;
    }
    
    return config->frontend->flags.development->debug;
}

// File I/O functions (basic implementation)
taku_config_t *taku_config_load_from_file(const char *filename) {
    // This would need a JSON parser or similar to implement properly
    // For now, return a default configuration
    printf("Loading configuration from %s (not implemented)\n", filename);
    return taku_config_create();
}

int taku_config_save_to_file(const taku_config_t *config, const char *filename) {
    // This would need JSON serialization to implement properly
    printf("Saving configuration to %s (not implemented)\n", filename);
    return 0;
}
