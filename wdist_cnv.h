#ifndef __WDIST_CNV_H__
#define __WDIST_CNV_H__

#include "wdist_common.h"

int32_t wdist_cnv(char* outname, char* outname_end, char* cnvname, char* mapname, char* famname, char* phenoname, uint32_t cnv_calc_type, uint32_t cnv_kb, uint32_t cnv_max_kb, uint32_t cnv_score, uint32_t cnv_max_score, uint32_t cnv_sites, uint32_t cnv_max_sites, uint32_t cnv_intersect_filter_type, char* cnv_intersect_filter_fname, char* cnv_subset_fname, uint32_t cnv_overlap_type, double cnv_overlap_val, uint32_t cnv_freq_type, uint32_t cnv_freq_val, uint32_t mperm_val, uint32_t cnv_test_window, uint32_t segment_modifier, char* segment_spanning_fname, uint32_t cnv_indiv_mperms, uint32_t cnv_test_mperms, uint32_t cnv_test_region_mperms, uint32_t cnv_enrichment_test_mperms, Chrom_info* chrom_info_ptr);

int32_t wdist_gvar(char* outname, char* outname_end, char* gvarname, char* mapname, char* famname);

#endif // __WDIST_CNV_H__