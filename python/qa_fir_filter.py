#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2013 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks, filter
import liquiddsp_swig as liquiddsp

class qa_fir_filter (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block()

    def tearDown (self):
        self.tb = None

    def test_001 (self):
        decim = 1
        taps = 20*[0.5, 0.5]
        src_data = 40*[1+1j, 2+2j, 3+3j, 4+4j]

        src = blocks.vector_source_c(src_data)
        op1  = filter.fir_filter_ccf(decim, taps)
        op2  = liquiddsp.fir_filter(decim, taps)
        dst1 = blocks.vector_sink_c()
        dst2 = blocks.vector_sink_c()
        self.tb.connect(src, op1, dst1)
        self.tb.connect(src, op2, dst2)
        self.tb.run()

        expected_data = dst1.data()
        result_data = dst2.data()

        self.assertComplexTuplesAlmostEqual(expected_data, result_data, 5)

    def test_002 (self):
        decim = 4
        taps = 20*[0.5, 0.5]
        src_data = 40*[1+1j, 2+2j, 3+3j, 4+4j]

        src = blocks.vector_source_c(src_data)
        op1  = filter.fir_filter_ccf(decim, taps)
        op2  = liquiddsp.fir_filter(decim, taps)
        dst1 = blocks.vector_sink_c()
        dst2 = blocks.vector_sink_c()
        self.tb.connect(src, op1, dst1)
        self.tb.connect(src, op2, dst2)
        self.tb.run()

        expected_data = dst1.data()
        result_data = dst2.data()

        self.assertComplexTuplesAlmostEqual(expected_data, result_data, 5)

if __name__ == '__main__':
    gr_unittest.run(qa_fir_filter, "qa_fir_filter.xml")
