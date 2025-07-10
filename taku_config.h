#ifndef TAKU_CONFIG_H
#define TAKU_CONFIG_H

#include <stdbool.h>

// Forward declarations
typedef struct taku_config taku_config_t;
typedef struct general_config general_config_t;
typedef struct support_config support_config_t;
typedef struct phone_config phone_config_t;
typedef struct version_control_config version_control_config_t;
typedef struct issues_config issues_config_t;
typedef struct frontend_config frontend_config_t;
typedef struct flags_config flags_config_t;
typedef struct env_config env_config_t;
typedef struct backend_config backend_config_t;
typedef struct feature_flags_config feature_flags_config_t;
typedef struct terminal_config terminal_config_t;
typedef struct documentation_config documentation_config_t;
typedef struct dependencies_config dependencies_config_t;
typedef struct shell_deps shell_deps_t;
typedef struct c_deps c_deps_t;
typedef struct js_deps js_deps_t;

// Environment configuration
struct env_config {
    char *node_env;
    char *api_url;
    char *analytics_id;
};

// Frontend flags configuration
struct flags_config {
    bool debug;
    bool hot_reload;
    bool source_maps;
    env_config_t *env;
};

// Phone configuration
struct phone_config {
    char *country_code;
    char *number;
};

// Support configuration
struct support_config {
    char *email;
    char *url;
    phone_config_t *phone;
};

// Issues configuration
struct issues_config {
    char *url;
    char *template;
    char **labels;
    size_t labels_count;
};

// Version control configuration
struct version_control_config {
    char *system;
    char *repository;
    char *branch;
    issues_config_t *issues;
};

// General configuration
struct general_config {
    char *name;
    char *author;
    char *group;
    char *license;
};

// Frontend configuration
struct frontend_config {
    char *type;
    char *build_command;
    struct {
        flags_config_t *development;
        flags_config_t *production;
        flags_config_t *testing;
    } flags;
};

// Feature flags configuration
struct feature_flags_config {
    bool default_flag;
};

// Backend configuration
struct backend_config {
    char *type;
    char *build_command;
    feature_flags_config_t *feature_flags;
};

// Terminal configuration
struct terminal_config {
    char *type;
    char *config_file;
    char **plugins;
    size_t plugins_count;
    struct {
        char *l;  // ls -la alias
    } aliases;
    env_config_t *env;
};

// Documentation configuration
struct documentation_config {
    char *readme;
    char *changelog;
    char *contributing;
    char *license;
    char *code_of_conduct;
    char *api_reference;
    char *tutorials;
    char *examples;
    char *faq;
    char *glossary;
    char *architecture;
    char *design;
    char *roadmap;
    char *security;
    char *migration;
    char *troubleshooting;
    char *best_practices;
    char *style_guide;
    char *api_docs;
    char *user_guide;
    char *developer_guide;
    char *release_notes;
    char *system_requirements;
    char *installation;
    char *configuration;
    char *deployment;
    char *usage;
    char *performance;
    char *testing;
    char *debugging;
    char *logging;
    char *monitoring;
    char *analytics;
    char *localization;
    char *internationalization;
    char *accessibility;
    char *compliance;
    char *data_privacy;
    char *data_protection;
    char *data_retention;
    char *data_security;
    char *data_governance;
    char *data_management;
    char *data_quality;
    char *data_integrity;
    char *data_migration;
    char *data_architecture;
    char *data_modeling;
    char *data_analysis;
    char *data_visualization;
    char *data_science;
    char *data_engineering;
    char *data_analytics;
    char *data_integration;
    char *data_processing;
    char *data_storage;
    char *data_retrieval;
    char *data_caching;
    char *environment_setup;
    char *release_management;
    char *error_codes;
    char *configuration_examples;
    char *security_practices;
    char *third_party_integrations;
    char *build_and_ci_cd;
    char *code_examples;
    char *community_guidelines;
    char *system_architecture;
    char *api_rate_limits;
    char *localization_and_translation;
    char *data_backup_and_recovery;
    char *command_line_reference;
    char *dependency_management;
    char *roadmap_and_vision;
    char *known_issues;
    char *user_feedback;
    char *testing_framework;
    char *performance_benchmarks;
    char *deployment_strategies;
    char *scalability;
    char *observability;
    char *incident_response;
    char *disaster_recovery;
    char *compliance_and_regulations;
    char *onboarding_guide;
    char *feature_flags;
    char *api_versioning;
    char *data_retention_policy;
    char *accessibility_testing;
    char *mobile_support;
    char *browser_compatibility;
    char *hardware_requirements;
    char *network_requirements;
    char *encryption_standards;
    char *logging_and_auditing;
    char *data_sharding;
    char *containerization;
    char *virtualization;
    char *cloud_integration;
    char *edge_computing;
    char *artificial_intelligence;
    char *machine_learning;
    char *blockchain;
    char *quantum_computing;
    char *green_computing;
    char *ethical_guidelines;
    char *open_source_contributions;
    char *sponsorship_and_funding;
    char *marketing_and_outreach;
    char *user_personas;
    char *competitive_analysis;
    char *product_positioning;
    char *pricing_models;
    char *licensing_models;
    char *intellectual_property;
    char *legal_disclaimers;
    char *terms_of_service;
    char *privacy_policy;
    char *cookie_policy;
    char *acceptable_use_policy;
    char *end_user_license_agreement;
    char *support_policy;
    char *service_level_agreement;
    char *maintenance_policy;
    char *deprecation_policy;
    char *retirement_policy;
    char *migration_guide;
    char *upgrade_guide;
    char *rollback_guide;
    char *feature_comparison;
    char *case_studies;
    char *testimonials;
    char *press_kit;
    char *media_coverage;
    char *awards_and_recognition;
    char *community_projects;
    char *hackathons;
    char *developer_tools;
    char *api_clients;
    char *sdk_documentation;
    char *plugin_documentation;
    char *extension_documentation;
    char *theme_documentation;
    char *widget_documentation;
    char *module_documentation;
    char *integration_guides;
    char *customization_guides;
    char *optimization_guides;
    char *troubleshooting_guides;
    char *faq_guides;
    char *glossary_guides;
    char *architecture_guides;
    char *design_guides;
    char *roadmap_guides;
    char *security_guides;
    char *migration_guides;
    char *best_practices_guides;
    char *style_guides;
    char *api_docs_guides;
    char *user_guides;
    char *developer_guides;
    char *release_notes_guides;
    char *system_requirements_guides;
    char *installation_guides;
    char *configuration_guides;
    char *deployment_guides;
    char *usage_guides;
    char *performance_guides;
    char *testing_guides;
    char *debugging_guides;
    char *logging_guides;
    char *monitoring_guides;
    char *analytics_guides;
    char *localization_guides;
    char *internationalization_guides;
    char *accessibility_guides;
    char *compliance_guides;
    char *data_privacy_guides;
    char *data_protection_guides;
    char *data_retention_guides;
    char *data_security_guides;
    char *data_governance_guides;
    char *data_management_guides;
    char *data_quality_guides;
    char *data_integrity_guides;
    char *data_migration_guides;
    char *data_architecture_guides;
    char *data_modeling_guides;
    char *data_analysis_guides;
    char *data_visualization_guides;
    char *data_science_guides;
    char *data_engineering_guides;
    char *data_analytics_guides;
    char *data_integration_guides;
    char *data_processing_guides;
    char *data_storage_guides;
    char *data_retrieval_guides;
    char *data_caching_guides;
};

// Shell dependencies
struct shell_deps {
    char *jq;
};

// C dependencies
struct c_deps {
    char *gcc;
    char *make;
    char *node;
};

// JavaScript dependencies
struct js_deps {
    char *consola;
};

// Dependencies configuration
struct dependencies_config {
    shell_deps_t *sh;
    c_deps_t *c;
    js_deps_t *js;
};

// Main configuration structure
struct taku_config {
    general_config_t *general;
    support_config_t *support;
    version_control_config_t *version_control;
    frontend_config_t *frontend;
    backend_config_t *backend;
    terminal_config_t *terminal;
    documentation_config_t *documentation;
    dependencies_config_t *dependencies;
};

// Function prototypes for memory management
taku_config_t *taku_config_create(void);
void taku_config_destroy(taku_config_t *config);

// Function prototypes for configuration loading
taku_config_t *taku_config_load_from_file(const char *filename);
int taku_config_save_to_file(const taku_config_t *config, const char *filename);

// Function prototypes for configuration validation
bool taku_config_validate(const taku_config_t *config);

// Function prototypes for individual section management
general_config_t *general_config_create(const char *name, const char *author, const char *group, const char *license);
void general_config_destroy(general_config_t *config);

support_config_t *support_config_create(const char *email, const char *url, const char *country_code, const char *number);
void support_config_destroy(support_config_t *config);

version_control_config_t *version_control_config_create(const char *system, const char *repository, const char *branch);
void version_control_config_destroy(version_control_config_t *config);

frontend_config_t *frontend_config_create(const char *type, const char *build_command);
void frontend_config_destroy(frontend_config_t *config);

backend_config_t *backend_config_create(const char *type, const char *build_command);
void backend_config_destroy(backend_config_t *config);

terminal_config_t *terminal_config_create(const char *type, const char *config_file);
void terminal_config_destroy(terminal_config_t *config);

documentation_config_t *documentation_config_create(void);
void documentation_config_destroy(documentation_config_t *config);

dependencies_config_t *dependencies_config_create(void);
void dependencies_config_destroy(dependencies_config_t *config);

// Utility functions
char *taku_config_get_project_path(const taku_config_t *config);
char *taku_config_get_build_command(const taku_config_t *config, const char *target);
bool taku_config_is_development_mode(const taku_config_t *config);

#endif // TAKU_CONFIG_H
