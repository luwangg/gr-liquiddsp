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


#ifndef INCLUDED_LIQUIDDSP_FIR_FILTER_H
#define INCLUDED_LIQUIDDSP_FIR_FILTER_H

#include <liquiddsp/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace liquiddsp {

    /*!
     * \brief <+description of block+>
     * \ingroup liquiddsp
     *
     */
    class LIQUIDDSP_API fir_filter : virtual public gr::sync_decimator
    {
     public:
      typedef boost::shared_ptr<fir_filter> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of liquiddsp::fir_filter.
       *
       * To avoid accidental use of raw pointers, liquiddsp::fir_filter's
       * constructor is in a private implementation
       * class. liquiddsp::fir_filter::make is the public interface for
       * creating new instances.
       */
      static sptr make(int decim, std::vector<float> taps);
    };

  } // namespace liquiddsp
} // namespace gr

#endif /* INCLUDED_LIQUIDDSP_FIR_FILTER_H */

