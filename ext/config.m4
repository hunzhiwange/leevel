PHP_ARG_ENABLE(leevel, whether to enable leevel, [ --enable-leevel   Enable Leevel])

if test "$PHP_LEEVEL" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, LEEVEL_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_LEEVEL, 1, [Whether you have Leevel])
	leevel_sources="leevel.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c leevel/support/facade.zep.c
	leevel/di/provider.zep.c
	leevel/support/imacro.zep.c
	leevel/support/iarray.zep.c
	leevel/support/ijson.zep.c
	leevel/flow/icontrol.zep.c
	leevel/http/iresponse.zep.c
	leevel/di/icontainer.zep.c
	leevel/http/bag.zep.c
	leevel/http/response.zep.c
	leevel/manager/manager.zep.c
	leevel/view/connect.zep.c
	leevel/view/iconnect.zep.c
	leevel/log/iconnect.zep.c
	leevel/mvc/iview.zep.c
	leevel/cache/connect.zep.c
	leevel/cache/iconnect.zep.c
	leevel/session/connect.zep.c
	leevel/cache/icache.zep.c
	leevel/cache/redis/iconnect.zep.c
	leevel/cookie/icookie.zep.c
	leevel/di/container.zep.c
	leevel/event/idispatch.zep.c
	leevel/event/isubject.zep.c
	leevel/http/file.zep.c
	leevel/http/fileexception.zep.c
	leevel/http/headerbag.zep.c
	leevel/http/irequest.zep.c
	leevel/http/jsonresponse.zep.c
	leevel/i18n/ii18n.zep.c
	leevel/kernel/ikernel.zep.c
	leevel/kernel/iproject.zep.c
	leevel/log/connect.zep.c
	leevel/log/ilog.zep.c
	leevel/mvc/icontroller.zep.c
	leevel/option/ioption.zep.c
	leevel/pipeline/ipipeline.zep.c
	leevel/router/iresponsefactory.zep.c
	leevel/router/irouter.zep.c
	leevel/router/iurl.zep.c
	leevel/router/match/imatch.zep.c
	leevel/session/isession.zep.c
	leevel/view/iview.zep.c
	leevel/auth.zep.c
	leevel/auth/provider/register.zep.c
	leevel/bootstrap/bootstrap/loadi18n.zep.c
	leevel/bootstrap/bootstrap/loadoption.zep.c
	leevel/bootstrap/bootstrap/registerruntime.zep.c
	leevel/bootstrap/bootstrap/traverseprovider.zep.c
	leevel/bootstrap/kernel.zep.c
	leevel/bootstrap/project.zep.c
	leevel/cache.zep.c
	leevel/cache/cache.zep.c
	leevel/cache/file.zep.c
	leevel/cache/load.zep.c
	leevel/cache/manager.zep.c
	leevel/cache/provider/register.zep.c
	leevel/cache/redis.zep.c
	leevel/cache/redis/phpredis.zep.c
	leevel/collection/collection.zep.c
	leevel/cookie.zep.c
	leevel/cookie/cookie.zep.c
	leevel/database.zep.c
	leevel/database/provider/register.zep.c
	leevel/db.zep.c
	leevel/di/containerinvalidargumentexception.zep.c
	leevel/encryption.zep.c
	leevel/encryption/provider/register.zep.c
	leevel/event.zep.c
	leevel/event/dispatch.zep.c
	leevel/event/eventprovider.zep.c
	leevel/event/observer.zep.c
	leevel/event/provider/register.zep.c
	leevel/event/subject.zep.c
	leevel/filesystem.zep.c
	leevel/filesystem/provider/register.zep.c
	leevel/http/apiresponse.zep.c
	leevel/http/filebag.zep.c
	leevel/http/filenotfoundexception.zep.c
	leevel/http/fileresponse.zep.c
	leevel/http/redirectresponse.zep.c
	leevel/http/request.zep.c
	leevel/http/responseheaderbag.zep.c
	leevel/http/serverbag.zep.c
	leevel/http/uploadedfile.zep.c
	leevel/i18n.zep.c
	leevel/i18n/i18n.zep.c
	leevel/leevel.zep.c
	leevel/log.zep.c
	leevel/log/file.zep.c
	leevel/log/log.zep.c
	leevel/log/manager.zep.c
	leevel/log/middleware/log.zep.c
	leevel/log/provider/register.zep.c
	leevel/log/syslog.zep.c
	leevel/mail.zep.c
	leevel/mail/provider/register.zep.c
	leevel/mvc/controller.zep.c
	leevel/mvc/view.zep.c
	leevel/option.zep.c
	leevel/option/option.zep.c
	leevel/page.zep.c
	leevel/pipeline/pipeline.zep.c
	leevel/request.zep.c
	leevel/response.zep.c
	leevel/router.zep.c
	leevel/router/match/pathinfo.zep.c
	leevel/router/provider/register.zep.c
	leevel/router/responsefactory.zep.c
	leevel/router/router.zep.c
	leevel/router/routerprovider.zep.c
	leevel/router/url.zep.c
	leevel/session.zep.c
	leevel/session/file.zep.c
	leevel/session/manager.zep.c
	leevel/session/middleware/session.zep.c
	leevel/session/nulls.zep.c
	leevel/session/provider/register.zep.c
	leevel/session/redis.zep.c
	leevel/session/session.zep.c
	leevel/support/debug/console.zep.c
	leevel/support/ihtml.zep.c
	leevel/support/str.zep.c
	leevel/support/type.zep.c
	leevel/throttler.zep.c
	leevel/throttler/provider/register.zep.c
	leevel/url.zep.c
	leevel/validate.zep.c
	leevel/validate/provider/register.zep.c
	leevel/view.zep.c
	leevel/view/html.zep.c
	leevel/view/manager.zep.c
	leevel/view/phpui.zep.c
	leevel/view/provider/register.zep.c
	leevel/view/twig.zep.c
	leevel/view/v8js.zep.c
	leevel/view/view.zep.c "
	PHP_NEW_EXTENSION(leevel, $leevel_sources, $ext_shared,, )
	PHP_SUBST(LEEVEL_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([leevel], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([leevel], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/leevel], [php_LEEVEL.h])

fi
