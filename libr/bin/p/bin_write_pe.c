/* radare - LGPL - Copyright 2009-2017 - pancake, nibble */

#include <r_types.h>
#include <r_bin.h>
#include "pe/pe.h"

static bool scn_perms(RBinFile *arch, const char *name, int perms) {
	struct PE_(r_bin_pe_obj_t) *obj = arch->o->bin_obj;
	bool ret = PE_(r_bin_pe_section_perms) (arch->o->bin_obj, name, perms);
	r_buf_free (arch->buf);
	arch->buf = obj->b;
	obj->b = NULL;
	return ret;
}

#if !R_BIN_PE64
RBinWrite r_bin_write_pe = {
	.scn_perms = &scn_perms
};
#endif
