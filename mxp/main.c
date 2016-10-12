#include <stdio.h>
#include "debug_control.h"
#include "unit_test.h"
#include "vbx.h"
#include "vbx_test.h"

void mxp_init();

int main(void) {
	mxp_init();
	//TODO: enable this once block optimizer is complete
	//main_cnn_app();
	printf("Application complete\n");
	return 0;
}



void mxp_init() {
#ifdef USE_MXP_SIM
	// Simulator init
	REL_INFO("Initializing MXP Simulator\n");
	vbxsim_init(16,     //vector_lanes
		64,     //KB scratchpad_size
		256,    //max masked waves
		16,     //fractional_bits (word)
		15,     //fractional_bits (half)
		4);     //fractional_bits (byte)
#elif !defined(CNN_SIMULATOR)
	REL_INFO("MXP Initialization....\n");
	vbx_test_init();
	vbx_timestamp_start();
#endif
}

