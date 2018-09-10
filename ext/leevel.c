
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "leevel.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *leevel_support_imacro_ce;
zend_class_entry *leevel_support_iarray_ce;
zend_class_entry *leevel_support_ijson_ce;
zend_class_entry *leevel_flow_icontrol_ce;
zend_class_entry *leevel_http_iresponse_ce;
zend_class_entry *leevel_di_icontainer_ce;
zend_class_entry *leevel_view_iconnect_ce;
zend_class_entry *leevel_log_iconnect_ce;
zend_class_entry *leevel_mvc_iview_ce;
zend_class_entry *leevel_cache_iconnect_ce;
zend_class_entry *leevel_cache_icache_ce;
zend_class_entry *leevel_cache_redis_iconnect_ce;
zend_class_entry *leevel_cookie_icookie_ce;
zend_class_entry *leevel_event_idispatch_ce;
zend_class_entry *leevel_event_isubject_ce;
zend_class_entry *leevel_http_irequest_ce;
zend_class_entry *leevel_i18n_ii18n_ce;
zend_class_entry *leevel_kernel_ikernel_ce;
zend_class_entry *leevel_kernel_iproject_ce;
zend_class_entry *leevel_log_ilog_ce;
zend_class_entry *leevel_mvc_icontroller_ce;
zend_class_entry *leevel_option_ioption_ce;
zend_class_entry *leevel_pipeline_ipipeline_ce;
zend_class_entry *leevel_router_iresponsefactory_ce;
zend_class_entry *leevel_router_irouter_ce;
zend_class_entry *leevel_router_iurl_ce;
zend_class_entry *leevel_router_match_imatch_ce;
zend_class_entry *leevel_session_isession_ce;
zend_class_entry *leevel_view_iview_ce;
zend_class_entry *leevel_support_ihtml_ce;
zend_class_entry *leevel_support_facade_ce;
zend_class_entry *leevel_di_provider_ce;
zend_class_entry *leevel_http_bag_ce;
zend_class_entry *leevel_http_response_ce;
zend_class_entry *leevel_manager_manager_ce;
zend_class_entry *leevel_view_connect_ce;
zend_class_entry *leevel_cache_connect_ce;
zend_class_entry *leevel_session_connect_ce;
zend_class_entry *leevel_di_container_ce;
zend_class_entry *leevel_http_file_ce;
zend_class_entry *leevel_http_fileexception_ce;
zend_class_entry *leevel_http_headerbag_ce;
zend_class_entry *leevel_http_jsonresponse_ce;
zend_class_entry *leevel_log_connect_ce;
zend_class_entry *leevel_auth_ce;
zend_class_entry *leevel_auth_provider_register_ce;
zend_class_entry *leevel_bootstrap_bootstrap_loadi18n_ce;
zend_class_entry *leevel_bootstrap_bootstrap_loadoption_ce;
zend_class_entry *leevel_bootstrap_bootstrap_registerruntime_ce;
zend_class_entry *leevel_bootstrap_bootstrap_traverseprovider_ce;
zend_class_entry *leevel_bootstrap_kernel_ce;
zend_class_entry *leevel_bootstrap_project_ce;
zend_class_entry *leevel_cache_cache_ce;
zend_class_entry *leevel_cache_ce;
zend_class_entry *leevel_cache_file_ce;
zend_class_entry *leevel_cache_load_ce;
zend_class_entry *leevel_cache_manager_ce;
zend_class_entry *leevel_cache_provider_register_ce;
zend_class_entry *leevel_cache_redis_ce;
zend_class_entry *leevel_cache_redis_phpredis_ce;
zend_class_entry *leevel_collection_collection_ce;
zend_class_entry *leevel_cookie_ce;
zend_class_entry *leevel_cookie_cookie_ce;
zend_class_entry *leevel_database_ce;
zend_class_entry *leevel_database_provider_register_ce;
zend_class_entry *leevel_db_ce;
zend_class_entry *leevel_di_containerinvalidargumentexception_ce;
zend_class_entry *leevel_encryption_ce;
zend_class_entry *leevel_encryption_provider_register_ce;
zend_class_entry *leevel_event_ce;
zend_class_entry *leevel_event_dispatch_ce;
zend_class_entry *leevel_event_eventprovider_ce;
zend_class_entry *leevel_event_observer_ce;
zend_class_entry *leevel_event_provider_register_ce;
zend_class_entry *leevel_event_subject_ce;
zend_class_entry *leevel_filesystem_ce;
zend_class_entry *leevel_filesystem_provider_register_ce;
zend_class_entry *leevel_http_apiresponse_ce;
zend_class_entry *leevel_http_filebag_ce;
zend_class_entry *leevel_http_filenotfoundexception_ce;
zend_class_entry *leevel_http_fileresponse_ce;
zend_class_entry *leevel_http_redirectresponse_ce;
zend_class_entry *leevel_http_request_ce;
zend_class_entry *leevel_http_responseheaderbag_ce;
zend_class_entry *leevel_http_serverbag_ce;
zend_class_entry *leevel_http_uploadedfile_ce;
zend_class_entry *leevel_i18n_ce;
zend_class_entry *leevel_i18n_i18n_ce;
zend_class_entry *leevel_leevel_ce;
zend_class_entry *leevel_log_ce;
zend_class_entry *leevel_log_file_ce;
zend_class_entry *leevel_log_log_ce;
zend_class_entry *leevel_log_manager_ce;
zend_class_entry *leevel_log_middleware_log_ce;
zend_class_entry *leevel_log_provider_register_ce;
zend_class_entry *leevel_log_syslog_ce;
zend_class_entry *leevel_mail_ce;
zend_class_entry *leevel_mail_provider_register_ce;
zend_class_entry *leevel_mvc_controller_ce;
zend_class_entry *leevel_mvc_view_ce;
zend_class_entry *leevel_option_ce;
zend_class_entry *leevel_option_option_ce;
zend_class_entry *leevel_page_ce;
zend_class_entry *leevel_pipeline_pipeline_ce;
zend_class_entry *leevel_request_ce;
zend_class_entry *leevel_response_ce;
zend_class_entry *leevel_router_ce;
zend_class_entry *leevel_router_match_pathinfo_ce;
zend_class_entry *leevel_router_provider_register_ce;
zend_class_entry *leevel_router_responsefactory_ce;
zend_class_entry *leevel_router_router_ce;
zend_class_entry *leevel_router_routerprovider_ce;
zend_class_entry *leevel_router_url_ce;
zend_class_entry *leevel_session_ce;
zend_class_entry *leevel_session_file_ce;
zend_class_entry *leevel_session_manager_ce;
zend_class_entry *leevel_session_middleware_session_ce;
zend_class_entry *leevel_session_nulls_ce;
zend_class_entry *leevel_session_provider_register_ce;
zend_class_entry *leevel_session_redis_ce;
zend_class_entry *leevel_session_session_ce;
zend_class_entry *leevel_support_debug_console_ce;
zend_class_entry *leevel_support_str_ce;
zend_class_entry *leevel_support_type_ce;
zend_class_entry *leevel_throttler_ce;
zend_class_entry *leevel_throttler_provider_register_ce;
zend_class_entry *leevel_url_ce;
zend_class_entry *leevel_validate_ce;
zend_class_entry *leevel_validate_provider_register_ce;
zend_class_entry *leevel_view_ce;
zend_class_entry *leevel_view_html_ce;
zend_class_entry *leevel_view_manager_ce;
zend_class_entry *leevel_view_phpui_ce;
zend_class_entry *leevel_view_provider_register_ce;
zend_class_entry *leevel_view_twig_ce;
zend_class_entry *leevel_view_v8js_ce;
zend_class_entry *leevel_view_view_ce;

ZEND_DECLARE_MODULE_GLOBALS(leevel)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(leevel)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Leevel_Support_IMacro);
	ZEPHIR_INIT(Leevel_Support_IArray);
	ZEPHIR_INIT(Leevel_Support_IJson);
	ZEPHIR_INIT(Leevel_Flow_IControl);
	ZEPHIR_INIT(Leevel_Http_IResponse);
	ZEPHIR_INIT(Leevel_Di_IContainer);
	ZEPHIR_INIT(Leevel_View_IConnect);
	ZEPHIR_INIT(Leevel_Log_IConnect);
	ZEPHIR_INIT(Leevel_Mvc_IView);
	ZEPHIR_INIT(Leevel_Cache_IConnect);
	ZEPHIR_INIT(Leevel_Cache_ICache);
	ZEPHIR_INIT(Leevel_Cache_Redis_IConnect);
	ZEPHIR_INIT(Leevel_Cookie_ICookie);
	ZEPHIR_INIT(Leevel_Event_IDispatch);
	ZEPHIR_INIT(Leevel_Event_ISubject);
	ZEPHIR_INIT(Leevel_Http_IRequest);
	ZEPHIR_INIT(Leevel_I18n_II18n);
	ZEPHIR_INIT(Leevel_Kernel_IKernel);
	ZEPHIR_INIT(Leevel_Kernel_IProject);
	ZEPHIR_INIT(Leevel_Log_ILog);
	ZEPHIR_INIT(Leevel_Mvc_IController);
	ZEPHIR_INIT(Leevel_Option_IOption);
	ZEPHIR_INIT(Leevel_Pipeline_IPipeline);
	ZEPHIR_INIT(Leevel_Router_IResponseFactory);
	ZEPHIR_INIT(Leevel_Router_IRouter);
	ZEPHIR_INIT(Leevel_Router_IUrl);
	ZEPHIR_INIT(Leevel_Router_Match_IMatch);
	ZEPHIR_INIT(Leevel_Session_ISession);
	ZEPHIR_INIT(Leevel_View_IView);
	ZEPHIR_INIT(Leevel_Support_IHtml);
	ZEPHIR_INIT(Leevel_Support_Facade);
	ZEPHIR_INIT(Leevel_Di_Provider);
	ZEPHIR_INIT(Leevel_Http_Bag);
	ZEPHIR_INIT(Leevel_Http_Response);
	ZEPHIR_INIT(Leevel_Manager_Manager);
	ZEPHIR_INIT(Leevel_View_Connect);
	ZEPHIR_INIT(Leevel_Cache_Connect);
	ZEPHIR_INIT(Leevel_Session_Connect);
	ZEPHIR_INIT(Leevel_Di_Container);
	ZEPHIR_INIT(Leevel_Http_File);
	ZEPHIR_INIT(Leevel_Http_FileException);
	ZEPHIR_INIT(Leevel_Http_HeaderBag);
	ZEPHIR_INIT(Leevel_Http_JsonResponse);
	ZEPHIR_INIT(Leevel_Log_Connect);
	ZEPHIR_INIT(Leevel_Auth);
	ZEPHIR_INIT(Leevel_Auth_Provider_Register);
	ZEPHIR_INIT(Leevel_Bootstrap_Bootstrap_LoadI18n);
	ZEPHIR_INIT(Leevel_Bootstrap_Bootstrap_LoadOption);
	ZEPHIR_INIT(Leevel_Bootstrap_Bootstrap_RegisterRuntime);
	ZEPHIR_INIT(Leevel_Bootstrap_Bootstrap_TraverseProvider);
	ZEPHIR_INIT(Leevel_Bootstrap_Kernel);
	ZEPHIR_INIT(Leevel_Bootstrap_Project);
	ZEPHIR_INIT(Leevel_Cache);
	ZEPHIR_INIT(Leevel_Cache_Cache);
	ZEPHIR_INIT(Leevel_Cache_File);
	ZEPHIR_INIT(Leevel_Cache_Load);
	ZEPHIR_INIT(Leevel_Cache_Manager);
	ZEPHIR_INIT(Leevel_Cache_Provider_Register);
	ZEPHIR_INIT(Leevel_Cache_Redis);
	ZEPHIR_INIT(Leevel_Cache_Redis_PhpRedis);
	ZEPHIR_INIT(Leevel_Collection_Collection);
	ZEPHIR_INIT(Leevel_Cookie);
	ZEPHIR_INIT(Leevel_Cookie_Cookie);
	ZEPHIR_INIT(Leevel_Database);
	ZEPHIR_INIT(Leevel_Database_Provider_Register);
	ZEPHIR_INIT(Leevel_Db);
	ZEPHIR_INIT(Leevel_Di_ContainerInvalidArgumentException);
	ZEPHIR_INIT(Leevel_Encryption);
	ZEPHIR_INIT(Leevel_Encryption_Provider_Register);
	ZEPHIR_INIT(Leevel_Event);
	ZEPHIR_INIT(Leevel_Event_Dispatch);
	ZEPHIR_INIT(Leevel_Event_EventProvider);
	ZEPHIR_INIT(Leevel_Event_Observer);
	ZEPHIR_INIT(Leevel_Event_Provider_Register);
	ZEPHIR_INIT(Leevel_Event_Subject);
	ZEPHIR_INIT(Leevel_Filesystem);
	ZEPHIR_INIT(Leevel_Filesystem_Provider_Register);
	ZEPHIR_INIT(Leevel_Http_ApiResponse);
	ZEPHIR_INIT(Leevel_Http_FileBag);
	ZEPHIR_INIT(Leevel_Http_FileNotFoundException);
	ZEPHIR_INIT(Leevel_Http_FileResponse);
	ZEPHIR_INIT(Leevel_Http_RedirectResponse);
	ZEPHIR_INIT(Leevel_Http_Request);
	ZEPHIR_INIT(Leevel_Http_ResponseHeaderBag);
	ZEPHIR_INIT(Leevel_Http_ServerBag);
	ZEPHIR_INIT(Leevel_Http_UploadedFile);
	ZEPHIR_INIT(Leevel_I18n);
	ZEPHIR_INIT(Leevel_I18n_I18n);
	ZEPHIR_INIT(Leevel_Leevel);
	ZEPHIR_INIT(Leevel_Log);
	ZEPHIR_INIT(Leevel_Log_File);
	ZEPHIR_INIT(Leevel_Log_Log);
	ZEPHIR_INIT(Leevel_Log_Manager);
	ZEPHIR_INIT(Leevel_Log_Middleware_Log);
	ZEPHIR_INIT(Leevel_Log_Provider_Register);
	ZEPHIR_INIT(Leevel_Log_Syslog);
	ZEPHIR_INIT(Leevel_Mail);
	ZEPHIR_INIT(Leevel_Mail_Provider_Register);
	ZEPHIR_INIT(Leevel_Mvc_Controller);
	ZEPHIR_INIT(Leevel_Mvc_View);
	ZEPHIR_INIT(Leevel_Option);
	ZEPHIR_INIT(Leevel_Option_Option);
	ZEPHIR_INIT(Leevel_Page);
	ZEPHIR_INIT(Leevel_Pipeline_Pipeline);
	ZEPHIR_INIT(Leevel_Request);
	ZEPHIR_INIT(Leevel_Response);
	ZEPHIR_INIT(Leevel_Router);
	ZEPHIR_INIT(Leevel_Router_Match_PathInfo);
	ZEPHIR_INIT(Leevel_Router_Provider_Register);
	ZEPHIR_INIT(Leevel_Router_ResponseFactory);
	ZEPHIR_INIT(Leevel_Router_Router);
	ZEPHIR_INIT(Leevel_Router_RouterProvider);
	ZEPHIR_INIT(Leevel_Router_Url);
	ZEPHIR_INIT(Leevel_Session);
	ZEPHIR_INIT(Leevel_Session_File);
	ZEPHIR_INIT(Leevel_Session_Manager);
	ZEPHIR_INIT(Leevel_Session_Middleware_Session);
	ZEPHIR_INIT(Leevel_Session_Nulls);
	ZEPHIR_INIT(Leevel_Session_Provider_Register);
	ZEPHIR_INIT(Leevel_Session_Redis);
	ZEPHIR_INIT(Leevel_Session_Session);
	ZEPHIR_INIT(Leevel_Support_Debug_Console);
	ZEPHIR_INIT(Leevel_Support_Str);
	ZEPHIR_INIT(Leevel_Support_Type);
	ZEPHIR_INIT(Leevel_Throttler);
	ZEPHIR_INIT(Leevel_Throttler_Provider_Register);
	ZEPHIR_INIT(Leevel_Url);
	ZEPHIR_INIT(Leevel_Validate);
	ZEPHIR_INIT(Leevel_Validate_Provider_Register);
	ZEPHIR_INIT(Leevel_View);
	ZEPHIR_INIT(Leevel_View_Html);
	ZEPHIR_INIT(Leevel_View_Manager);
	ZEPHIR_INIT(Leevel_View_Phpui);
	ZEPHIR_INIT(Leevel_View_Provider_Register);
	ZEPHIR_INIT(Leevel_View_Twig);
	ZEPHIR_INIT(Leevel_View_V8js);
	ZEPHIR_INIT(Leevel_View_View);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(leevel)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_leevel_globals *leevel_globals TSRMLS_DC)
{
	leevel_globals->initialized = 0;

	/* Memory options */
	leevel_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	leevel_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	leevel_globals->cache_enabled = 1;

	/* Recursive Lock */
	leevel_globals->recursive_lock = 0;

	/* Static cache */
	memset(leevel_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_leevel_globals *leevel_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(leevel)
{

	zend_leevel_globals *leevel_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	leevel_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(leevel_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(leevel_globals_ptr TSRMLS_CC);

	zephir_init_static_properties_Leevel_Support_Facade(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_Response(TSRMLS_C);
	zephir_init_static_properties_Leevel_Cache_Cache(TSRMLS_C);
	zephir_init_static_properties_Leevel_Collection_Collection(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_FileBag(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_Request(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_UploadedFile(TSRMLS_C);
	zephir_init_static_properties_Leevel_Router_Router(TSRMLS_C);
	zephir_init_static_properties_Leevel_Support_Str(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(leevel)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(leevel)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_LEEVEL_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_LEEVEL_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_LEEVEL_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_LEEVEL_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_LEEVEL_ZEPVERSION);
	php_info_print_table_end();
	php_info_print_table_start();
	php_info_print_table_header(2, "Leevel Support", "Enabled");
	php_info_print_table_row(2, "QQ Group", "288751294");
	php_info_print_table_row(2, "Office Site", "https://www.queryphp.com");
	php_info_print_table_row(2, "Github", "https://github.com/hunzhiwange/leevel");
	php_info_print_table_row(2, "Issues", "https://github.com/hunzhiwange/leevel/issues");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(leevel)
{
	php_zephir_init_globals(leevel_globals TSRMLS_CC);
	php_zephir_init_module_globals(leevel_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(leevel)
{

}


zend_function_entry php_leevel_functions[] = {
ZEND_FE_END

};

zend_module_entry leevel_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_LEEVEL_EXTNAME,
	php_leevel_functions,
	PHP_MINIT(leevel),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(leevel),
#else
	NULL,
#endif
	PHP_RINIT(leevel),
	PHP_RSHUTDOWN(leevel),
	PHP_MINFO(leevel),
	PHP_LEEVEL_VERSION,
	ZEND_MODULE_GLOBALS(leevel),
	PHP_GINIT(leevel),
	PHP_GSHUTDOWN(leevel),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_LEEVEL
ZEND_GET_MODULE(leevel)
#endif
