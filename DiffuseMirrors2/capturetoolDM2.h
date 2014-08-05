
#ifndef __CAPTURETOOLDM2_H
#define __CAPTURETOOLDM2_H

#include "global.h"
#include "data_read.h"
#include <vector>


// Author: Jaime Martin (modification of process_data())
void process_data_to_buffer(int w, int h, std::vector<std::pair<int, unsigned short* > > &shutters, unsigned short* ushort_img[2], int pass = 0);

bool dir_exists(const std::string& dirName_in);

// Author: Jaime Martin
bool file_exists (const std::string& name);

// Author: Jaime Martin
// str_is_number ()
bool str_is_number (std::string & str);

// Author: Jaime Martin
// char_array_to_float_vector (...)
void char_array_to_float_vector (char* & char_array, std::vector<float> & float_vector, float min, float max);

// Author: Jaime Martin
// parser_main(...)
// return 0:  No errors parsing
// return -1: Errors parsing
int parser_main (int argc, char *argv[], std::vector<float> & frequencies, std::vector<float> & delays, std::vector<float> & shutters_float, char* dir_name, char* file_name, char* comport, int & numtakes);

// Author: Jaime Martin
// check_parameters(...)
// return 0: all parameters OK
// return 1: any parameter out of bounds, modified
// return 2: unproper dimensions or size
int check_parameters (float frequency_, float shutter_, char* comport);

// Author: Jaime Martin
// check_parameters_vector(...)
// return 0: all parameters OK
// return 1: any parameter out of bounds, modified
// return 2: unproper dimensions or size
int check_parameters_vector (std::vector<float> & frequencies, std::vector<float> & delays, std::vector<float> & shutters_float, char* comport, int & numtakes);

// Author: Jaime Martin
// PMD_charArray_to_file
int PMD_charArray_to_file (int argc, char *argv[]);

// Author: Jaime Martin (modification of previous function)
// PMD_params_to_file
int PMD_params_to_file (std::vector<float> & frequencies, std::vector<float> & delays, std::vector<float> & shutters_float, char* dir_name, char* file_name, char* comport, int & numtakes);

// Author: Jaime Martin
// copy_array (...)
// return 0: no error, in bounds
// return 1: error, out of bounds
int copy_array (unsigned short int* dst, unsigned short int* src, int dst_pos, int dst_size, int src_size);

// Author: Jaime Martin (modification of previous function)
// PMD_params_to_DataPMD
int PMD_params_to_DataPMD (DataPMD & DataPMD_cap, std::vector<float> & frequencies, std::vector<float> & delays, std::vector<float> & shutters_float, char* comport, int & numtakes, bool loop);

// Author: Jaime Martin (modification of previous function)
// PMD_params_to_DataPMD
int PMD_params_to_Frame (Frame & Frame_00_cap, Frame & Frame_90_cap, float frequency_, float distance_, float shutter_, char* comport, bool loop);

// Author: Jaime Martin 
// MAIN
int capturetoolDM2_main(int argc, char *argv[]);


#endif
