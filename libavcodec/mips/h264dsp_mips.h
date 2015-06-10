/*
 * Copyright (c) 2015 Parag Salasakar (Parag.Salasakar@imgtec.com)
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef H264_DSP_MIPS_H
#define H264_DSP_MIPS_H

#include "libavcodec/h264.h"

void ff_h264_h_lpf_luma_inter_msa(uint8_t *src, int stride,
                                  int alpha, int beta, int8_t *tc0);
void ff_h264_v_lpf_luma_inter_msa(uint8_t *src, int stride,
                                  int alpha, int beta, int8_t *tc0);
void ff_h264_h_lpf_chroma_inter_msa(uint8_t *src, int stride,
                                    int alpha, int beta, int8_t *tc0);
void ff_h264_v_lpf_chroma_inter_msa(uint8_t *src, int stride,
                                    int alpha, int beta, int8_t *tc0);
void ff_h264_h_loop_filter_chroma422_msa(uint8_t *src, int32_t stride,
                                         int32_t alpha, int32_t beta,
                                         int8_t *tc0);
void ff_h264_h_loop_filter_chroma422_mbaff_msa(uint8_t *src, int32_t stride,
                                               int32_t alpha, int32_t beta,
                                               int8_t *tc0);
void ff_h264_h_loop_filter_luma_mbaff_msa(uint8_t *src, int32_t stride,
                                          int32_t alpha, int32_t beta,
                                          int8_t *tc0);

void ff_h264_h_lpf_luma_intra_msa(uint8_t *src, int stride,
                                  int alpha, int beta);
void ff_h264_v_lpf_luma_intra_msa(uint8_t *src, int stride,
                                  int alpha, int beta);
void ff_h264_h_lpf_chroma_intra_msa(uint8_t *src, int stride,
                                    int alpha, int beta);
void ff_h264_v_lpf_chroma_intra_msa(uint8_t *src, int stride,
                                    int alpha, int beta);
void ff_h264_h_loop_filter_luma_mbaff_intra_msa(uint8_t *src, int stride,
                                                int alpha, int beta);

void ff_biweight_h264_pixels16_8_msa(uint8_t *dst, uint8_t *src,
                                     int stride, int height, int log2_denom,
                                     int weightd, int weights, int offset);
void ff_biweight_h264_pixels8_8_msa(uint8_t *dst, uint8_t *src,
                                    int stride, int height, int log2_denom,
                                    int weightd, int weights, int offset);
void ff_biweight_h264_pixels4_8_msa(uint8_t *dst, uint8_t *src,
                                    int stride, int height, int log2_denom,
                                    int weightd, int weights, int offset);
void ff_weight_h264_pixels16_8_msa(uint8_t *src, int stride, int height,
                                   int log2_denom, int weight, int offset);
void ff_weight_h264_pixels8_8_msa(uint8_t *src, int stride, int height,
                                  int log2_denom, int weight, int offset);
void ff_weight_h264_pixels4_8_msa(uint8_t *src, int stride, int height,
                                  int log2_denom, int weight, int offset);

void ff_h264_intra_predict_plane_8x8_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_predict_dc_4blk_8x8_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_predict_hor_dc_8x8_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_predict_vert_dc_8x8_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_predict_mad_cow_dc_l0t_8x8_msa(uint8_t *src,
                                                  ptrdiff_t stride);
void ff_h264_intra_predict_mad_cow_dc_0lt_8x8_msa(uint8_t *src,
                                                  ptrdiff_t stride);
void ff_h264_intra_predict_mad_cow_dc_l00_8x8_msa(uint8_t *src,
                                                  ptrdiff_t stride);
void ff_h264_intra_predict_mad_cow_dc_0l0_8x8_msa(uint8_t *src,
                                                  ptrdiff_t stride);
void ff_h264_intra_predict_plane_16x16_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_vert_8x8_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_horiz_8x8_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_dc_16x16_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_vert_16x16_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_horiz_16x16_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_dc_left_16x16_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_dc_top_16x16_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_dc_128_8x8_msa(uint8_t *src, ptrdiff_t stride);
void ff_h264_intra_pred_dc_128_16x16_msa(uint8_t *src, ptrdiff_t stride);
void ff_vp8_pred8x8_127_dc_8_msa(uint8_t *src, ptrdiff_t stride);
void ff_vp8_pred8x8_129_dc_8_msa(uint8_t *src, ptrdiff_t stride);
void ff_vp8_pred16x16_127_dc_8_msa(uint8_t *src, ptrdiff_t stride);
void ff_vp8_pred16x16_129_dc_8_msa(uint8_t *src, ptrdiff_t stride);

void ff_h264_weight_pixels16_8_mmi(uint8_t *block, int stride, int height,
        int log2_denom, int weight, int offset);
void ff_h264_biweight_pixels16_8_mmi(uint8_t *dst, uint8_t *src,
        int stride, int height, int log2_denom, int weightd, int weights,
        int offset);
void ff_h264_weight_pixels8_8_mmi(uint8_t *block, int stride, int height,
        int log2_denom, int weight, int offset);
void ff_h264_biweight_pixels8_8_mmi(uint8_t *dst, uint8_t *src,
        int stride, int height, int log2_denom, int weightd, int weights,
        int offset);
void ff_h264_weight_pixels4_8_mmi(uint8_t *block, int stride, int height,
        int log2_denom, int weight, int offset);
void ff_h264_biweight_pixels4_8_mmi(uint8_t *dst, uint8_t *src,
        int stride, int height, int log2_denom, int weightd, int weights,
        int offset);

#endif  // #ifndef H264_DSP_MIPS_H
