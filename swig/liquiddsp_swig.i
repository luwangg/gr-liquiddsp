/* -*- c++ -*- */

#define LIQUIDDSP_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "liquiddsp_swig_doc.i"

%{
#include "liquiddsp/fft.h"
#include "liquiddsp/fir_filter.h"
%}


%include "liquiddsp/fft.h"
GR_SWIG_BLOCK_MAGIC2(liquiddsp, fft);
%include "liquiddsp/fir_filter.h"
GR_SWIG_BLOCK_MAGIC2(liquiddsp, fir_filter);
