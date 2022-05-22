#include "main.h"

/**
 * init_params - reset buffer and clear struct fields
 * @params: struct of the parameters 
 * @ap: pointer to the argument
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->add_flag = 0;
	params->empty_flag = 0;
	params->hash_flag = 0;
	params->null_flag = 0;
	params->not_flag = 0;

	params->width = 0;
	params->precise = UINT_MAX;

	params->h_mod = 0;
	params->l_mod = 0;
	(void)ap;
}
