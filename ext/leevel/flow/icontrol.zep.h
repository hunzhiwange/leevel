
extern zend_class_entry *leevel_flow_icontrol_ce;

ZEPHIR_INIT_CLASS(Leevel_Flow_IControl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_flow_icontrol_ifs, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_flow_icontrol_elseifs, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_flow_icontrol_settcontrol, 0, 0, 2)
	ZEND_ARG_INFO(0, inFlowControl)
	ZEND_ARG_INFO(0, isFlowControlTrue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_flow_icontrol_placeholdertcontrol, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_flow_icontrol_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Flow_IControl, ifs, arginfo_leevel_flow_icontrol_ifs)
	PHP_ABSTRACT_ME(Leevel_Flow_IControl, elseIfs, arginfo_leevel_flow_icontrol_elseifs)
	PHP_ABSTRACT_ME(Leevel_Flow_IControl, elses, NULL)
	PHP_ABSTRACT_ME(Leevel_Flow_IControl, endIfs, NULL)
	PHP_ABSTRACT_ME(Leevel_Flow_IControl, setTControl, arginfo_leevel_flow_icontrol_settcontrol)
	PHP_ABSTRACT_ME(Leevel_Flow_IControl, checkTControl, NULL)
	PHP_ABSTRACT_ME(Leevel_Flow_IControl, placeholderTControl, arginfo_leevel_flow_icontrol_placeholdertcontrol)
	PHP_FE_END
};
