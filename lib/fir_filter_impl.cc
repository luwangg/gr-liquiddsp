/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "fir_filter_impl.h"

namespace gr {
  namespace liquiddsp {

    fir_filter::sptr
    fir_filter::make(int decim, std::vector<float> taps)
    {
      return gnuradio::get_initial_sptr
        (new fir_filter_impl(decim, taps));
    }

    /*
     * The private constructor
     */
    fir_filter_impl::fir_filter_impl(int decim, std::vector<float> taps)
      : gr::sync_decimator("fir_filter",
                           gr::io_signature::make(1, 1, sizeof(gr_complex)),
                           gr::io_signature::make(1, 1, sizeof(gr_complex)),
                           decim)
    {
      d_decim = decim;
      d_taps = taps;
      d_fir = firdecim_crcf_create(d_decim, &d_taps[0], taps.size());
    }

    /*
     * Our virtual destructor.
     */
    fir_filter_impl::~fir_filter_impl()
    {
      firdecim_crcf_destroy(d_fir);
    }

    int
    fir_filter_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
      gr_complex *in = (gr_complex*)input_items[0];
      gr_complex *out = (gr_complex*)output_items[0];

      unsigned int sample_phase = 0;  // decimator output sample phase, [0,k-1]
      for(int i = 0; i < noutput_items; i++) {
        firdecim_crcf_execute(d_fir, &in[d_decim*i], &out[i], sample_phase);
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace liquiddsp */
} /* namespace gr */

