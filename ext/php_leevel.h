
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_LEEVEL_H
#define PHP_LEEVEL_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_LEEVEL_NAME        "leevel"
#define PHP_LEEVEL_VERSION     "1.0.0"
#define PHP_LEEVEL_EXTNAME     "leevel"
#define PHP_LEEVEL_AUTHOR      "Xiangmin Liu <635750556@qq.com>"
#define PHP_LEEVEL_ZEPVERSION  "0.10.7-8059e66568"
#define PHP_LEEVEL_DESCRIPTION "The Leevel Framework To Rebuild QueryPHP"



ZEND_BEGIN_MODULE_GLOBALS(leevel)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(leevel)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(leevel)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(leevel, v)
#else
	#define ZEPHIR_GLOBAL(v) (leevel_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_leevel_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(leevel_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(leevel_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def leevel_globals
#define zend_zephir_globals_def zend_leevel_globals

extern zend_module_entry leevel_module_entry;
#define phpext_leevel_ptr &leevel_module_entry

#endif
