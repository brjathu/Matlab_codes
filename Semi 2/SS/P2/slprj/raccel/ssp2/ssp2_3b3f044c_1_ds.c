#include "__cf_ssp2.h"
#include "ne_ds.h"
#include "ssp2_3b3f044c_1_ds.h"
#ifndef struct__NeDynamicSystemTag
#define struct__NeDynamicSystemTag
typedef struct _NeDynamicSystemTag { NeDynamicSystem mBase ; int32_T mRefCnt
; NeAllocator mAlloc ; } _NeDynamicSystem ;
#else
typedef struct _NeDynamicSystemTag _NeDynamicSystem ;
#endif
static int32_T ds_s ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out ) ; static int32_T ds_m_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_m ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_vmm
( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxm_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dum_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dtm_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_a_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_a (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_b_p ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_c_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_f ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_vmf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_slf ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxf ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_duf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dtf_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dtf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_ddf_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_tduf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_tdxf_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_y ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxy ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_duy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dty_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_mode ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_zc ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_r ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_assert ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T stub_method ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out ) ; static NeDsMethodOutput * ds_output_s (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_m_p ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_m ( const NeDynamicSystem *
ds , NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_vmm (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxm_p ( const NeDynamicSystem * ds , NeAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_dxm ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dum_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dum ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtm_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dtm ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_a_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_a ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_b_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_b ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_c_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_c ( const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_f ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_vmf ( const NeDynamicSystem
* ds , NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_slf (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxf_p ( const NeDynamicSystem * ds , NeAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_dxf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_duf_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_duf ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dtf ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_ddf_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_ddf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_tduf_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_tdxf_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_y ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxy_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dxy ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_duy_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_duy ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dty_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dty ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_mode ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_zc ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_cache ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_update_r ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_update_i ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_sfo ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_sfp ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_init_r ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_init_i (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_r ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_log ( const NeDynamicSystem
* ds , NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_assert
( const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_del_t ( const NeDynamicSystem * ds , NeAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_del_v ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_del_v0 ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_del_tmax ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dxdelt_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxdelt ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dudelt_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dudelt ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtdelt_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dtdelt ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static void release_reference ( NeDynamicSystem *
ds ) ; static void get_reference ( NeDynamicSystem * ds ) ; static
NeEquationData s_equation_data [ 16 ] = { { "ssp2.Capacitor1" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "ssp2/Capacitor1" , 1U , 0U , TRUE , 1.0 } , {
"ssp2.Inductor1" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "ssp2/Inductor1" , 1U ,
1U , TRUE , 1.0 } , { "ssp2.Pulse_Voltage_Source.volt_src" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "ssp2/Pulse Voltage Source" , 1U , 2U , TRUE , 1.0
} , { "ssp2.Capacitor1" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"ssp2/Capacitor1" , 1U , 3U , TRUE , 1.0 } , { "ssp2.Capacitor1" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "ssp2/Capacitor1" , 1U , 4U , TRUE , 1.0 } , {
"ssp2.Inductor1" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "ssp2/Inductor1" , 1U ,
5U , TRUE , 1.0 } , { "ssp2.Inductor1" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"ssp2/Inductor1" , 1U , 6U , TRUE , 1.0 } , { "ssp2.Electrical_Reference" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "ssp2/Electrical Reference" , 1U , 7U ,
TRUE , 1.0 } , { "ssp2.Resistor1" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"ssp2/Resistor1" , 1U , 8U , TRUE , 1.0 } , { "ssp2.Resistor1" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "ssp2/Resistor1" , 1U , 9U , TRUE , 0.004 } , {
"ssp2.Voltage_Sensor" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"ssp2/Voltage Sensor" , 1U , 10U , TRUE , 1.0 } , { "ssp2.Voltage_Sensor" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "ssp2/Voltage Sensor" , 1U , 11U , TRUE ,
1.0 } , { "ssp2.Voltage_Sensor" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"ssp2/Voltage Sensor" , 1U , 12U , TRUE , 1.0 } , {
"ssp2.Electrical_Reference_V" , 0U , 33 , NE_EQUATION_DOMAIN_TIME ,
"ssp2/Electrical Reference" , 0U , 13U , FALSE , 1.0 } , {
"ssp2.Capacitor1_p" , 0U , 33 , NE_EQUATION_DOMAIN_TIME , "ssp2/Capacitor1" ,
0U , 13U , FALSE , 1.0 } , { "ssp2.Inductor1_n" , 0U , 33 ,
NE_EQUATION_DOMAIN_TIME , "ssp2/Inductor1" , 0U , 13U , FALSE , 1.0 } } ;
static NeVariableData s_variable_data [ 16 ] = { { "ssp2.Capacitor1.vc" , 0U
, 0 , "ssp2/Capacitor1" , 1.0 , "V" , 0.0 , FALSE , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Capacitor voltage" } , { "ssp2.Inductor1.i_L" , 0U , 0 ,
"ssp2/Inductor1" , 1.0 , "A" , 0.0 , FALSE , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Inductor current" } , { "ssp2.Capacitor1.p.v" , 0U , 1 ,
"ssp2/Capacitor1" , 1.0 , "V" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "v" } , { "ssp2.Capacitor1.i" , 0U , 0 ,
"ssp2/Capacitor1" , 1.0 , "A" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Current" } , { "ssp2.Capacitor1.v" , 0U , 0 ,
"ssp2/Capacitor1" , 1.0 , "V" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" } , { "ssp2.Electrical_Reference.i" , 0U , 0 ,
"ssp2/Electrical Reference" , 1.0 , "A" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Current" } , { "ssp2.Inductor1.n.v" , 0U , 1 ,
"ssp2/Inductor1" , 1.0 , "V" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "v" } , { "ssp2.Inductor1.i" , 0U , 0 , "ssp2/Inductor1"
, 1.0 , "A" , 0.0 , FALSE , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Current" }
, { "ssp2.Inductor1.v" , 0U , 0 , "ssp2/Inductor1" , 1.0 , "V" , 0.0 , FALSE
, FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Voltage" } , {
"ssp2.Pulse_Voltage_Source.n.v" , 0U , 1 , "ssp2/Pulse Voltage Source" , 1.0
, "V" , 0.0 , FALSE , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "v" } , {
"ssp2.Pulse_Voltage_Source.p.v" , 0U , 1 , "ssp2/Pulse Voltage Source" , 1.0
, "V" , 0.0 , FALSE , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "v" } , {
"ssp2.Resistor1.i" , 0U , 0 , "ssp2/Resistor1" , 1.0 , "A" , 0.0 , FALSE ,
FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Current" } , { "ssp2.Resistor1.v" , 0U
, 0 , "ssp2/Resistor1" , 1.0 , "V" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" } , { "ssp2.Voltage_Sensor.i1" , 0U , 0 ,
"ssp2/Voltage Sensor" , 1.0 , "A" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Current" } , { "ssp2.Voltage_Sensor.v1" , 0U , 0 ,
"ssp2/Voltage Sensor" , 1.0 , "V" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" } , { "ssp2.Voltage_Sensor.V" , 0U , 2 ,
"ssp2/Voltage Sensor" , 1.0 , "V" , 0.0 , FALSE , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "V" } } ; static NeVariableData * s_discrete_data = NULL
; static NeModeData * s_major_mode_data = NULL ; static NeZCData s_zc_data [
11 ] = { { "ssp2/Pulse Voltage Source" , 1U , 0U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_TRUE } , { "ssp2/Pulse Voltage Source" , 1U , 1U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_EITHER } , { "ssp2/Pulse Voltage Source" , 1U , 2U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_EITHER } , { "ssp2/Pulse Voltage Source" , 1U , 3U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_TRUE } , { "ssp2/Pulse Voltage Source" , 1U , 4U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_FALSE } , { "ssp2/Pulse Voltage Source" , 1U , 5U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_TRUE } , { "ssp2/Pulse Voltage Source" , 1U , 6U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_FALSE } , { "ssp2/Pulse Voltage Source" , 1U , 7U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_FALSE } , { "ssp2/Pulse Voltage Source" , 1U , 8U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_TRUE } , { "ssp2/Pulse Voltage Source" , 1U , 9U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_TRUE } , { "ssp2/Pulse Voltage Source" , 1U , 10U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
NE_ZC_TYPE_TRUE } } ; static NeRange s_range [ 11 ] = { {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } } ; static NeAssertData
s_assert_data [ 2 ] = { { "ssp2/Pulse Voltage Source" , 1U , 0U ,
"ssp2.Pulse_Voltage_Source.volt_src" , "Pulse Voltage Source Inf Function" ,
FALSE , "Input must be non zero" ,
"equation_language:matrix:NonZeroInputRequired" } , {
"ssp2/Pulse Voltage Source" , 1U , 1U , "ssp2.Pulse_Voltage_Source.volt_src"
, "Pulse Voltage Source Inf Function" , FALSE , "Input must be non zero" ,
"equation_language:matrix:NonZeroInputRequired" } } ; static NeRange
s_assert_range [ 2 ] = { {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } } ; static NeRange
s_equation_range [ 13 ] = { {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 45U , 5U , 45U , 25U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 43U , 5U , 43U , 23U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/elec/elec/+elec/+additional/+spice/+sources/volt_pulse_inf_fcn.sscp"
, 0U , 0U , 0U , 0U , NE_RANGE_TYPE_PROTECTED } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 44U , 5U , 44U , 18U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/inductor.ssc"
, 44U , 5U , 44U , 19U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/reference.ssc"
, 21U , 5U , 21U , 13U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/resistor.ssc"
, 26U , 5U , 26U , 13U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/voltage.ssc"
, 32U , 5U , 32U , 20U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/voltage.ssc"
, 33U , 5U , 33U , 12U , NE_RANGE_TYPE_NORMAL } , {
 "/home/brjathu/Softwares/Matlab/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/voltage.ssc"
, 34U , 5U , 34U , 12U , NE_RANGE_TYPE_NORMAL } } ; static int32_T ds_s (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeIntVector local0 ; ( void ) in ; local0 = out1
-> mS ; local0 . mX [ 0UL ] = 1 ; local0 . mX [ 1UL ] = 1 ; local0 . mX [ 2UL
] = 0 ; local0 . mX [ 3UL ] = 0 ; local0 . mX [ 4UL ] = 0 ; local0 . mX [ 5UL
] = 0 ; local0 . mX [ 6UL ] = 0 ; local0 . mX [ 7UL ] = 0 ; local0 . mX [ 8UL
] = 0 ; local0 . mX [ 9UL ] = 0 ; local0 . mX [ 10UL ] = 0 ; local0 . mX [
11UL ] = 0 ; local0 . mX [ 12UL ] = 0 ; local0 . mX [ 13UL ] = 0 ; local0 .
mX [ 14UL ] = 0 ; local0 . mX [ 15UL ] = 0 ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_m_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mM_P ; local0 . mJc [ 0UL ] = 0 ;
local0 . mJc [ 1UL ] = 1 ; local0 . mJc [ 2UL ] = 2 ; local0 . mJc [ 3UL ] =
2 ; local0 . mJc [ 4UL ] = 2 ; local0 . mJc [ 5UL ] = 2 ; local0 . mJc [ 6UL
] = 2 ; local0 . mJc [ 7UL ] = 2 ; local0 . mJc [ 8UL ] = 2 ; local0 . mJc [
9UL ] = 2 ; local0 . mJc [ 10UL ] = 2 ; local0 . mJc [ 11UL ] = 2 ; local0 .
mJc [ 12UL ] = 2 ; local0 . mJc [ 13UL ] = 2 ; local0 . mJc [ 14UL ] = 2 ;
local0 . mJc [ 15UL ] = 2 ; local0 . mJc [ 16UL ] = 2 ; local0 . mIr [ 0UL ]
= 0 ; local0 . mIr [ 1UL ] = 1 ; ( void ) ds ; ( void ) in ; return 0 ; }
static int32_T ds_m ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out1 ) { NeRealVector local0 ; ( void ) in ; local0
= out1 -> mM ; local0 . mX [ 0UL ] = 0.01 ; local0 . mX [ 1UL ] = 100.0 ; (
void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_vmm ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeBoolVector local0 ; ( void ) in ; local0 = out1 -> mVMM ; local0 .
mX [ 0 ] = false ; local0 . mX [ 1 ] = false ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_dxm_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mDXM_P ; local0 . mJc [ 0UL ] = 0 ;
local0 . mJc [ 1UL ] = 0 ; local0 . mJc [ 2UL ] = 0 ; local0 . mJc [ 3UL ] =
0 ; local0 . mJc [ 4UL ] = 0 ; local0 . mJc [ 5UL ] = 0 ; local0 . mJc [ 6UL
] = 0 ; local0 . mJc [ 7UL ] = 0 ; local0 . mJc [ 8UL ] = 0 ; local0 . mJc [
9UL ] = 0 ; local0 . mJc [ 10UL ] = 0 ; local0 . mJc [ 11UL ] = 0 ; local0 .
mJc [ 12UL ] = 0 ; local0 . mJc [ 13UL ] = 0 ; local0 . mJc [ 14UL ] = 0 ;
local0 . mJc [ 15UL ] = 0 ; local0 . mJc [ 16UL ] = 0 ; ( void ) ds ; ( void
) in ; return 0 ; } static int32_T ds_dum_p ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) {
NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mDUM_P ; local0 .
mJc [ 0UL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T
ds_dtm_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 =
out1 -> mDTM_P ; local0 . mJc [ 0UL ] = 0 ; local0 . mJc [ 1UL ] = 0 ; ( void
) ds ; ( void ) in ; return 0 ; } static int32_T ds_a_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mA_P ;
local0 . mJc [ 0UL ] = 0 ; local0 . mJc [ 1UL ] = 1 ; local0 . mJc [ 2UL ] =
2 ; local0 . mJc [ 3UL ] = 5 ; local0 . mJc [ 4UL ] = 9 ; local0 . mJc [ 5UL
] = 11 ; local0 . mJc [ 6UL ] = 12 ; local0 . mJc [ 7UL ] = 15 ; local0 . mJc
[ 8UL ] = 18 ; local0 . mJc [ 9UL ] = 21 ; local0 . mJc [ 10UL ] = 23 ;
local0 . mJc [ 11UL ] = 24 ; local0 . mJc [ 12UL ] = 27 ; local0 . mJc [ 13UL
] = 29 ; local0 . mJc [ 14UL ] = 32 ; local0 . mJc [ 15UL ] = 34 ; local0 .
mJc [ 16UL ] = 35 ; local0 . mIr [ 0UL ] = 4 ; local0 . mIr [ 1UL ] = 6 ;
local0 . mIr [ 2UL ] = 3 ; local0 . mIr [ 3UL ] = 8 ; local0 . mIr [ 4UL ] =
10 ; local0 . mIr [ 5UL ] = 0 ; local0 . mIr [ 6UL ] = 4 ; local0 . mIr [ 7UL
] = 13 ; local0 . mIr [ 8UL ] = 14 ; local0 . mIr [ 9UL ] = 3 ; local0 . mIr
[ 10UL ] = 4 ; local0 . mIr [ 11UL ] = 13 ; local0 . mIr [ 12UL ] = 5 ;
local0 . mIr [ 13UL ] = 8 ; local0 . mIr [ 14UL ] = 10 ; local0 . mIr [ 15UL
] = 6 ; local0 . mIr [ 16UL ] = 13 ; local0 . mIr [ 17UL ] = 15 ; local0 .
mIr [ 18UL ] = 1 ; local0 . mIr [ 19UL ] = 5 ; local0 . mIr [ 20UL ] = 6 ;
local0 . mIr [ 21UL ] = 5 ; local0 . mIr [ 22UL ] = 7 ; local0 . mIr [ 23UL ]
= 3 ; local0 . mIr [ 24UL ] = 9 ; local0 . mIr [ 25UL ] = 14 ; local0 . mIr [
26UL ] = 15 ; local0 . mIr [ 27UL ] = 8 ; local0 . mIr [ 28UL ] = 9 ; local0
. mIr [ 29UL ] = 11 ; local0 . mIr [ 30UL ] = 14 ; local0 . mIr [ 31UL ] = 15
; local0 . mIr [ 32UL ] = 10 ; local0 . mIr [ 33UL ] = 12 ; local0 . mIr [
34UL ] = 12 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_a (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeRealVector local0 ; ( void ) in ; local0 = out1
-> mA ; local0 . mX [ 0UL ] = - 1.0 ; local0 . mX [ 1UL ] = - 1.0 ; local0 .
mX [ 2UL ] = - 1.0 ; local0 . mX [ 3UL ] = - 1.0 ; local0 . mX [ 4UL ] = -
1.0 ; local0 . mX [ 5UL ] = 1.0 ; local0 . mX [ 6UL ] = - 1.0E-6 ; local0 .
mX [ 7UL ] = - 1.0 ; local0 . mX [ 8UL ] = 1.0 ; local0 . mX [ 9UL ] = 1.0 ;
local0 . mX [ 10UL ] = 1.0 ; local0 . mX [ 11UL ] = 1.0 ; local0 . mX [ 12UL
] = 1.0 ; local0 . mX [ 13UL ] = 1.0 ; local0 . mX [ 14UL ] = 1.0 ; local0 .
mX [ 15UL ] = 1.0 ; local0 . mX [ 16UL ] = 1.0 ; local0 . mX [ 17UL ] = - 1.0
; local0 . mX [ 18UL ] = 1.0 ; local0 . mX [ 19UL ] = 1.0 ; local0 . mX [
20UL ] = - 1.0E-9 ; local0 . mX [ 21UL ] = - 1.0 ; local0 . mX [ 22UL ] = -
1.0 ; local0 . mX [ 23UL ] = 1.0 ; local0 . mX [ 24UL ] = - 1.0 ; local0 . mX
[ 25UL ] = 1.0 ; local0 . mX [ 26UL ] = - 1.0 ; local0 . mX [ 27UL ] = 1.0 ;
local0 . mX [ 28UL ] = 0.004 ; local0 . mX [ 29UL ] = - 1.0 ; local0 . mX [
30UL ] = 1.0 ; local0 . mX [ 31UL ] = - 1.0 ; local0 . mX [ 32UL ] = 1.0 ;
local0 . mX [ 33UL ] = - 1.0 ; local0 . mX [ 34UL ] = 1.0 ; ( void ) ds ; (
void ) in ; return 0 ; } static int32_T ds_b_p ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) {
NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mB_P ; local0 . mJc
[ 0UL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_c_p
( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 =
out1 -> mC_P ; local0 . mJc [ 0UL ] = 0 ; local0 . mJc [ 1UL ] = 0 ; ( void )
ds ; ( void ) in ; return 0 ; } static int32_T ds_f ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { int32_T M
[ 10 ] ; NeRealVector local0 ; real_T x [ 16 ] ; size_t idx ; int32_T
localMode [ 10 ] ; real_T T_idx_0 ; real_T X_idx_10 ; real_T X_idx_9 ;
int32_T in_idx_0 ; int32_T in_idx_1 ; int32_T in_idx_2 ; int32_T in_idx_3 ;
int32_T in_idx_4 ; int32_T in_idx_5 ; int32_T in_idx_6 ; int32_T in_idx_7 ;
int32_T in_idx_8 ; int32_T in_idx_9 ; in_idx_0 = in -> mM . mX [ 0 ] ;
in_idx_1 = in -> mM . mX [ 1 ] ; in_idx_2 = in -> mM . mX [ 2 ] ; in_idx_3 =
in -> mM . mX [ 3 ] ; in_idx_4 = in -> mM . mX [ 4 ] ; in_idx_5 = in -> mM .
mX [ 5 ] ; in_idx_6 = in -> mM . mX [ 6 ] ; in_idx_7 = in -> mM . mX [ 7 ] ;
in_idx_8 = in -> mM . mX [ 8 ] ; in_idx_9 = in -> mM . mX [ 9 ] ; M [ 0 ] =
in_idx_0 ; M [ 1 ] = in_idx_1 ; M [ 2 ] = in_idx_2 ; M [ 3 ] = in_idx_3 ; M [
4 ] = in_idx_4 ; M [ 5 ] = in_idx_5 ; M [ 6 ] = in_idx_6 ; M [ 7 ] = in_idx_7
; M [ 8 ] = in_idx_8 ; M [ 9 ] = in_idx_9 ; T_idx_0 = in -> mT . mX [ 0 ] ;
X_idx_9 = in -> mX . mX [ 9 ] ; X_idx_10 = in -> mX . mX [ 10 ] ; local0 =
out1 -> mF ; for ( idx = 0UL ; idx < 16UL ; idx ++ ) { x [ idx ] = 0.0 ; }
memcpy ( & localMode [ 0 ] , & M [ 0 ] , 40U ) ; T_idx_0 = ( boolean_T )
localMode [ 5UL ] && ( boolean_T ) localMode [ 4UL ] ? X_idx_10 - X_idx_9 -
10.0 * T_idx_0 : X_idx_10 - X_idx_9 - ( 10.0 - 10.0 * ( T_idx_0 - 1.1 ) / 1.1
) ; T_idx_0 = ( boolean_T ) localMode [ 1UL ] || ( boolean_T ) localMode [
0UL ] ? 0.0 - ( X_idx_10 - X_idx_9 ) : ( boolean_T ) localMode [ 3UL ] && (
boolean_T ) localMode [ 2UL ] ? 10.0 - ( X_idx_10 - X_idx_9 ) : T_idx_0 ;
local0 . mX [ 0UL ] = x [ 0UL ] ; local0 . mX [ 1UL ] = x [ 1UL ] ; local0 .
mX [ 2UL ] = T_idx_0 ; local0 . mX [ 3UL ] = x [ 3UL ] ; local0 . mX [ 4UL ]
= x [ 4UL ] ; local0 . mX [ 5UL ] = x [ 5UL ] ; local0 . mX [ 6UL ] = x [ 6UL
] ; local0 . mX [ 7UL ] = x [ 7UL ] ; local0 . mX [ 8UL ] = x [ 8UL ] ;
local0 . mX [ 9UL ] = 0.004 * x [ 9UL ] ; local0 . mX [ 10UL ] = x [ 10UL ] ;
local0 . mX [ 11UL ] = x [ 11UL ] ; local0 . mX [ 12UL ] = x [ 12UL ] ;
local0 . mX [ 13UL ] = x [ 13UL ] ; local0 . mX [ 14UL ] = x [ 14UL ] ;
local0 . mX [ 15UL ] = x [ 15UL ] ; ( void ) ds ; ( void ) in ; return 0 ; }
static int32_T ds_vmf ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeBoolVector local0 ;
boolean_T x [ 16 ] ; size_t idx ; ( void ) in ; local0 = out1 -> mVMF ; for (
idx = 0UL ; idx < 16UL ; idx ++ ) { x [ idx ] = false ; } local0 . mX [ 0 ] =
x [ 0 ] ; local0 . mX [ 1 ] = x [ 1 ] ; local0 . mX [ 2 ] = true ; local0 .
mX [ 3 ] = x [ 3 ] ; local0 . mX [ 4 ] = x [ 4 ] ; local0 . mX [ 5 ] = x [ 5
] ; local0 . mX [ 6 ] = x [ 6 ] ; local0 . mX [ 7 ] = x [ 7 ] ; local0 . mX [
8 ] = x [ 8 ] ; local0 . mX [ 9 ] = x [ 9 ] ; local0 . mX [ 10 ] = x [ 10 ] ;
local0 . mX [ 11 ] = x [ 11 ] ; local0 . mX [ 12 ] = x [ 12 ] ; local0 . mX [
13 ] = x [ 13 ] ; local0 . mX [ 14 ] = x [ 14 ] ; local0 . mX [ 15 ] = x [ 15
] ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_slf ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeBoolVector local0 ; boolean_T x [ 16 ] ; size_t idx ; ( void ) in
; local0 = out1 -> mSLF ; for ( idx = 0UL ; idx < 16UL ; idx ++ ) { x [ idx ]
= false ; } local0 . mX [ 0 ] = x [ 0 ] ; local0 . mX [ 1 ] = x [ 1 ] ;
local0 . mX [ 2 ] = x [ 2 ] ; local0 . mX [ 3 ] = x [ 3 ] ; local0 . mX [ 4 ]
= x [ 4 ] ; local0 . mX [ 5 ] = x [ 5 ] ; local0 . mX [ 6 ] = x [ 6 ] ;
local0 . mX [ 7 ] = x [ 7 ] ; local0 . mX [ 8 ] = x [ 8 ] ; local0 . mX [ 9 ]
= x [ 9 ] ; local0 . mX [ 10 ] = x [ 10 ] ; local0 . mX [ 11 ] = x [ 11 ] ;
local0 . mX [ 12 ] = x [ 12 ] ; local0 . mX [ 13 ] = x [ 13 ] ; local0 . mX [
14 ] = x [ 14 ] ; local0 . mX [ 15 ] = x [ 15 ] ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_dxf_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mDXF_P ; local0 . mJc [ 0UL ] = 0 ;
local0 . mJc [ 1UL ] = 0 ; local0 . mJc [ 2UL ] = 0 ; local0 . mJc [ 3UL ] =
0 ; local0 . mJc [ 4UL ] = 0 ; local0 . mJc [ 5UL ] = 0 ; local0 . mJc [ 6UL
] = 0 ; local0 . mJc [ 7UL ] = 0 ; local0 . mJc [ 8UL ] = 0 ; local0 . mJc [
9UL ] = 0 ; local0 . mJc [ 10UL ] = 1 ; local0 . mJc [ 11UL ] = 2 ; local0 .
mJc [ 12UL ] = 2 ; local0 . mJc [ 13UL ] = 2 ; local0 . mJc [ 14UL ] = 2 ;
local0 . mJc [ 15UL ] = 2 ; local0 . mJc [ 16UL ] = 2 ; local0 . mIr [ 0UL ]
= 2 ; local0 . mIr [ 1UL ] = 2 ; ( void ) ds ; ( void ) in ; return 0 ; }
static int32_T ds_dxf ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { int32_T M [ 10 ] ;
NeRealVector local0 ; int32_T localMode [ 10 ] ; boolean_T t5 ; boolean_T t6
; int32_T in_idx_0 ; int32_T in_idx_1 ; int32_T in_idx_2 ; int32_T in_idx_3 ;
int32_T in_idx_4 ; int32_T in_idx_5 ; int32_T in_idx_6 ; int32_T in_idx_7 ;
int32_T in_idx_8 ; int32_T in_idx_9 ; in_idx_0 = in -> mM . mX [ 0 ] ;
in_idx_1 = in -> mM . mX [ 1 ] ; in_idx_2 = in -> mM . mX [ 2 ] ; in_idx_3 =
in -> mM . mX [ 3 ] ; in_idx_4 = in -> mM . mX [ 4 ] ; in_idx_5 = in -> mM .
mX [ 5 ] ; in_idx_6 = in -> mM . mX [ 6 ] ; in_idx_7 = in -> mM . mX [ 7 ] ;
in_idx_8 = in -> mM . mX [ 8 ] ; in_idx_9 = in -> mM . mX [ 9 ] ; M [ 0 ] =
in_idx_0 ; M [ 1 ] = in_idx_1 ; M [ 2 ] = in_idx_2 ; M [ 3 ] = in_idx_3 ; M [
4 ] = in_idx_4 ; M [ 5 ] = in_idx_5 ; M [ 6 ] = in_idx_6 ; M [ 7 ] = in_idx_7
; M [ 8 ] = in_idx_8 ; M [ 9 ] = in_idx_9 ; local0 = out1 -> mDXF ; memcpy (
& localMode [ 0 ] , & M [ 0 ] , 40U ) ; t5 = ( boolean_T ) localMode [ 1UL ]
|| ( boolean_T ) localMode [ 0UL ] ; t6 = ( boolean_T ) localMode [ 3UL ] &&
( boolean_T ) localMode [ 2UL ] ; local0 . mX [ 0UL ] = t5 ? 1.0 : t6 ? 1.0 :
- 1.0 ; local0 . mX [ 1UL ] = t5 ? - 1.0 : t6 ? - 1.0 : 1.0 ; ( void ) ds ; (
void ) in ; return 0 ; } static int32_T ds_duf_p ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) {
NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mDUF_P ; local0 .
mJc [ 0UL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T
ds_dtf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 =
out1 -> mDTF_P ; local0 . mJc [ 0UL ] = 0 ; local0 . mJc [ 1UL ] = 1 ; local0
. mIr [ 0UL ] = 2 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T
ds_dtf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { int32_T M [ 10 ] ; NeRealVector local0 ; int32_T
localMode [ 10 ] ; boolean_T t5 ; boolean_T t6 ; real_T t10 ; real_T t13 ;
int32_T in_idx_0 ; int32_T in_idx_1 ; int32_T in_idx_2 ; int32_T in_idx_3 ;
int32_T in_idx_4 ; int32_T in_idx_5 ; int32_T in_idx_6 ; int32_T in_idx_7 ;
int32_T in_idx_8 ; int32_T in_idx_9 ; in_idx_0 = in -> mM . mX [ 0 ] ;
in_idx_1 = in -> mM . mX [ 1 ] ; in_idx_2 = in -> mM . mX [ 2 ] ; in_idx_3 =
in -> mM . mX [ 3 ] ; in_idx_4 = in -> mM . mX [ 4 ] ; in_idx_5 = in -> mM .
mX [ 5 ] ; in_idx_6 = in -> mM . mX [ 6 ] ; in_idx_7 = in -> mM . mX [ 7 ] ;
in_idx_8 = in -> mM . mX [ 8 ] ; in_idx_9 = in -> mM . mX [ 9 ] ; M [ 0 ] =
in_idx_0 ; M [ 1 ] = in_idx_1 ; M [ 2 ] = in_idx_2 ; M [ 3 ] = in_idx_3 ; M [
4 ] = in_idx_4 ; M [ 5 ] = in_idx_5 ; M [ 6 ] = in_idx_6 ; M [ 7 ] = in_idx_7
; M [ 8 ] = in_idx_8 ; M [ 9 ] = in_idx_9 ; local0 = out1 -> mDTF ; memcpy (
& localMode [ 0 ] , & M [ 0 ] , 40U ) ; t5 = ( boolean_T ) localMode [ 1UL ]
|| ( boolean_T ) localMode [ 0UL ] ; t6 = ( boolean_T ) localMode [ 3UL ] &&
( boolean_T ) localMode [ 2UL ] ; t10 = 1.0 ; t13 = 1.2100000000000002 ; t10
= ( boolean_T ) localMode [ 5UL ] && ( boolean_T ) localMode [ 4UL ] ? - (
10.0 / ( t10 == 0.0 ? 1.0E-16 : t10 ) ) : - ( - ( 11.0 / ( t13 == 0.0 ?
1.0E-16 : t13 ) ) ) ; local0 . mX [ 0UL ] = t5 ? 0.0 : t6 ? 0.0 : t10 ; (
void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_ddf_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mDDF_P ;
local0 . mJc [ 0UL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static
int32_T ds_tduf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ;
local0 = out1 -> mTDUF_P ; local0 . mJc [ 0UL ] = 0 ; ( void ) ds ; ( void )
in ; return 0 ; } static int32_T ds_tdxf_p ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) {
NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mTDXF_P ; local0 .
mJc [ 0UL ] = 0 ; local0 . mJc [ 1UL ] = 2 ; local0 . mJc [ 2UL ] = 4 ;
local0 . mJc [ 3UL ] = 7 ; local0 . mJc [ 4UL ] = 11 ; local0 . mJc [ 5UL ] =
13 ; local0 . mJc [ 6UL ] = 14 ; local0 . mJc [ 7UL ] = 17 ; local0 . mJc [
8UL ] = 20 ; local0 . mJc [ 9UL ] = 23 ; local0 . mJc [ 10UL ] = 26 ; local0
. mJc [ 11UL ] = 28 ; local0 . mJc [ 12UL ] = 31 ; local0 . mJc [ 13UL ] = 33
; local0 . mJc [ 14UL ] = 36 ; local0 . mJc [ 15UL ] = 38 ; local0 . mJc [
16UL ] = 39 ; local0 . mIr [ 0UL ] = 0 ; local0 . mIr [ 1UL ] = 4 ; local0 .
mIr [ 2UL ] = 1 ; local0 . mIr [ 3UL ] = 6 ; local0 . mIr [ 4UL ] = 3 ;
local0 . mIr [ 5UL ] = 8 ; local0 . mIr [ 6UL ] = 10 ; local0 . mIr [ 7UL ] =
0 ; local0 . mIr [ 8UL ] = 4 ; local0 . mIr [ 9UL ] = 13 ; local0 . mIr [
10UL ] = 14 ; local0 . mIr [ 11UL ] = 3 ; local0 . mIr [ 12UL ] = 4 ; local0
. mIr [ 13UL ] = 13 ; local0 . mIr [ 14UL ] = 5 ; local0 . mIr [ 15UL ] = 8 ;
local0 . mIr [ 16UL ] = 10 ; local0 . mIr [ 17UL ] = 6 ; local0 . mIr [ 18UL
] = 13 ; local0 . mIr [ 19UL ] = 15 ; local0 . mIr [ 20UL ] = 1 ; local0 .
mIr [ 21UL ] = 5 ; local0 . mIr [ 22UL ] = 6 ; local0 . mIr [ 23UL ] = 2 ;
local0 . mIr [ 24UL ] = 5 ; local0 . mIr [ 25UL ] = 7 ; local0 . mIr [ 26UL ]
= 2 ; local0 . mIr [ 27UL ] = 3 ; local0 . mIr [ 28UL ] = 9 ; local0 . mIr [
29UL ] = 14 ; local0 . mIr [ 30UL ] = 15 ; local0 . mIr [ 31UL ] = 8 ; local0
. mIr [ 32UL ] = 9 ; local0 . mIr [ 33UL ] = 11 ; local0 . mIr [ 34UL ] = 14
; local0 . mIr [ 35UL ] = 15 ; local0 . mIr [ 36UL ] = 10 ; local0 . mIr [
37UL ] = 12 ; local0 . mIr [ 38UL ] = 12 ; ( void ) ds ; ( void ) in ; return
0 ; } static int32_T ds_y ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeRealVector local0 ;
real_T X_idx_15 ; X_idx_15 = in -> mX . mX [ 15 ] ; local0 = out1 -> mY ;
local0 . mX [ 0UL ] = X_idx_15 ; ( void ) ds ; ( void ) in ; return 0 ; }
static int32_T ds_dxy_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mDXY_P ; local0 . mJc [ 0UL ] = 0 ;
local0 . mJc [ 1UL ] = 0 ; local0 . mJc [ 2UL ] = 0 ; local0 . mJc [ 3UL ] =
0 ; local0 . mJc [ 4UL ] = 0 ; local0 . mJc [ 5UL ] = 0 ; local0 . mJc [ 6UL
] = 0 ; local0 . mJc [ 7UL ] = 0 ; local0 . mJc [ 8UL ] = 0 ; local0 . mJc [
9UL ] = 0 ; local0 . mJc [ 10UL ] = 0 ; local0 . mJc [ 11UL ] = 0 ; local0 .
mJc [ 12UL ] = 0 ; local0 . mJc [ 13UL ] = 0 ; local0 . mJc [ 14UL ] = 0 ;
local0 . mJc [ 15UL ] = 0 ; local0 . mJc [ 16UL ] = 1 ; local0 . mIr [ 0UL ]
= 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_dxy ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeRealVector local0 ; ( void ) in ; local0 = out1 -> mDXY ; local0 .
mX [ 0UL ] = 1.0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T
ds_duy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 =
out1 -> mDUY_P ; local0 . mJc [ 0UL ] = 0 ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_dty_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mDTY_P ; local0 . mJc [ 0UL ] = 0 ;
local0 . mJc [ 1UL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static
int32_T ds_mode ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out1 ) { NeIntVector local0 ; int32_T retv [ 10 ] ;
size_t idx ; boolean_T t11 ; real_T t13 ; real_T t14 ; real_T t16 ; real_T
t17 ; real_T t18 ; real_T T_idx_0 ; T_idx_0 = in -> mT . mX [ 0 ] ; local0 =
out1 -> mMODE ; t11 = 1.0 - T_idx_0 < T_idx_0 ; t13 = - ( t11 ? 1.0 - T_idx_0
: T_idx_0 ) ; t14 = - ( T_idx_0 - 2.2 > - T_idx_0 ? T_idx_0 - 2.2 : - T_idx_0
) ; t16 = t11 ? 1.0 - T_idx_0 : T_idx_0 ; t17 = 1.1 - T_idx_0 < T_idx_0 - 1.0
? 1.1 - T_idx_0 : T_idx_0 - 1.0 ; t18 = - t17 < t13 ? - t17 : t13 ; t13 = t14
< - t17 ? t14 : - t17 ; retv [ 0 ] = ( int32_T ) ( T_idx_0 >= 2.2 ) ; retv [
1 ] = ( int32_T ) ( T_idx_0 <= 0.0 ) ; retv [ 2 ] = ( int32_T ) ( T_idx_0 <=
1.1 ) ; retv [ 3 ] = ( int32_T ) ( T_idx_0 >= 1.0 ) ; retv [ 4 ] = ( int32_T
) ( T_idx_0 < 1.0 ) ; retv [ 5 ] = ( int32_T ) ( T_idx_0 > 0.0 ) ; retv [ 6 ]
= 1 ; retv [ 7 ] = ( int32_T ) ( ( - ( t16 < t13 ? t16 : t13 ) > 1.0 ? - (
t16 < t13 ? t16 : t13 ) : 1.0 ) == 0.0 ) ; retv [ 8 ] = 1 ; retv [ 9 ] = (
int32_T ) ( ( - ( t14 < t18 ? t14 : t18 ) > 1.1 ? - ( t14 < t18 ? t14 : t18 )
: 1.1 ) == 0.0 ) ; for ( idx = 0UL ; idx < 10UL ; idx ++ ) { local0 . mX [
idx ] = retv [ idx ] ; } ( void ) ds ; ( void ) in ; return 0 ; } static
int32_T ds_zc ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out1 ) { int32_T M [ 10 ] ; NeRealVector local0 ;
int32_T localMode [ 10 ] ; real_T retv [ 11 ] ; size_t idx ; boolean_T t7 ;
boolean_T t8 ; boolean_T t14 ; real_T t17 ; real_T t18 ; real_T t19 ; real_T
t21 ; real_T t22 ; real_T T_idx_0 ; int32_T in_idx_0 ; int32_T in_idx_1 ;
int32_T in_idx_2 ; int32_T in_idx_3 ; int32_T in_idx_4 ; int32_T in_idx_5 ;
int32_T in_idx_6 ; int32_T in_idx_7 ; int32_T in_idx_8 ; int32_T in_idx_9 ;
in_idx_0 = in -> mM . mX [ 0 ] ; in_idx_1 = in -> mM . mX [ 1 ] ; in_idx_2 =
in -> mM . mX [ 2 ] ; in_idx_3 = in -> mM . mX [ 3 ] ; in_idx_4 = in -> mM .
mX [ 4 ] ; in_idx_5 = in -> mM . mX [ 5 ] ; in_idx_6 = in -> mM . mX [ 6 ] ;
in_idx_7 = in -> mM . mX [ 7 ] ; in_idx_8 = in -> mM . mX [ 8 ] ; in_idx_9 =
in -> mM . mX [ 9 ] ; M [ 0 ] = in_idx_0 ; M [ 1 ] = in_idx_1 ; M [ 2 ] =
in_idx_2 ; M [ 3 ] = in_idx_3 ; M [ 4 ] = in_idx_4 ; M [ 5 ] = in_idx_5 ; M [
6 ] = in_idx_6 ; M [ 7 ] = in_idx_7 ; M [ 8 ] = in_idx_8 ; M [ 9 ] = in_idx_9
; T_idx_0 = in -> mT . mX [ 0 ] ; local0 = out1 -> mZC ; memcpy ( & localMode
[ 0 ] , & M [ 0 ] , 40U ) ; t7 = ( boolean_T ) localMode [ 7UL ] || (
boolean_T ) localMode [ 9UL ] ; t8 = ! ( ( boolean_T ) localMode [ 1UL ] || (
boolean_T ) localMode [ 0UL ] ) ; t14 = ! ( ( boolean_T ) localMode [ 3UL ]
&& ( boolean_T ) localMode [ 2UL ] ) && t8 ; t17 = T_idx_0 - 2.2 > - T_idx_0
? T_idx_0 - 2.2 : - T_idx_0 ; t18 = 1.0 - T_idx_0 < T_idx_0 ? 1.0 - T_idx_0 :
T_idx_0 ; t19 = - ( 1.1 - T_idx_0 < T_idx_0 - 1.0 ? 1.1 - T_idx_0 : T_idx_0 -
1.0 ) ; t21 = t19 < - t18 ? t19 : - t18 ; t22 = - t17 < t19 ? - t17 : t19 ;
t19 = - ( - t17 < t21 ? - t17 : t21 ) ; retv [ 0 ] = t8 ? 1.1 - T_idx_0 <
T_idx_0 - 1.0 ? 1.1 - T_idx_0 : T_idx_0 - 1.0 : 0.0 ; retv [ 1 ] = t19 > 1.1
? t19 : 1.1 ; retv [ 2 ] = - ( t18 < t22 ? t18 : t22 ) > 1.0 ? - ( t18 < t22
? t18 : t22 ) : 1.0 ; retv [ 3 ] = t17 ; retv [ 4 ] = t14 ? t18 : 0.0 ; retv
[ 5 ] = t7 ? - T_idx_0 : 0.0 ; retv [ 6 ] = t7 ? T_idx_0 : 0.0 ; retv [ 7 ] =
t7 ? 1.0 - T_idx_0 : 0.0 ; retv [ 8 ] = t7 ? 1.1 - T_idx_0 : 0.0 ; retv [ 9 ]
= t7 ? T_idx_0 - 1.0 : 0.0 ; retv [ 10 ] = t7 ? T_idx_0 - 2.2 : 0.0 ; for (
idx = 0UL ; idx < 11UL ; idx ++ ) { local0 . mX [ idx ] = retv [ idx ] ; } (
void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_r ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeRealVector local0 ; ( void ) in ; local0 = out1 -> mR ; local0 .
mX [ 0UL ] = 0.0 ; local0 . mX [ 1UL ] = 0.0 ; local0 . mX [ 2UL ] = 0.0 ;
local0 . mX [ 3UL ] = 2.0 ; local0 . mX [ 4UL ] = 0.0 ; local0 . mX [ 5UL ] =
1.0 ; local0 . mX [ 6UL ] = 0.0 ; local0 . mX [ 7UL ] = 1.0 ; local0 . mX [
8UL ] = 0.0 ; local0 . mX [ 9UL ] = 0.0 ; local0 . mX [ 10UL ] = 0.0 ; local0
. mX [ 11UL ] = 1.0 ; local0 . mX [ 12UL ] = 0.0 ; local0 . mX [ 13UL ] = 1.0
; local0 . mX [ 14UL ] = 0.0 ; local0 . mX [ 15UL ] = 0.0 ; ( void ) ds ; (
void ) in ; return 0 ; } static int32_T ds_assert ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { int32_T M
[ 10 ] ; NeIntVector local0 ; int32_T localMode [ 10 ] ; boolean_T t1 ;
boolean_T t2 ; int32_T in_idx_0 ; int32_T in_idx_1 ; int32_T in_idx_2 ;
int32_T in_idx_3 ; int32_T in_idx_4 ; int32_T in_idx_5 ; int32_T in_idx_6 ;
int32_T in_idx_7 ; int32_T in_idx_8 ; int32_T in_idx_9 ; in_idx_0 = in -> mM
. mX [ 0 ] ; in_idx_1 = in -> mM . mX [ 1 ] ; in_idx_2 = in -> mM . mX [ 2 ]
; in_idx_3 = in -> mM . mX [ 3 ] ; in_idx_4 = in -> mM . mX [ 4 ] ; in_idx_5
= in -> mM . mX [ 5 ] ; in_idx_6 = in -> mM . mX [ 6 ] ; in_idx_7 = in -> mM
. mX [ 7 ] ; in_idx_8 = in -> mM . mX [ 8 ] ; in_idx_9 = in -> mM . mX [ 9 ]
; M [ 0 ] = in_idx_0 ; M [ 1 ] = in_idx_1 ; M [ 2 ] = in_idx_2 ; M [ 3 ] =
in_idx_3 ; M [ 4 ] = in_idx_4 ; M [ 5 ] = in_idx_5 ; M [ 6 ] = in_idx_6 ; M [
7 ] = in_idx_7 ; M [ 8 ] = in_idx_8 ; M [ 9 ] = in_idx_9 ; local0 = out1 ->
mASSERT ; memcpy ( & localMode [ 0 ] , & M [ 0 ] , 40U ) ; t1 = ( ! ( (
boolean_T ) localMode [ 5UL ] && ( boolean_T ) localMode [ 4UL ] ) && ! ( (
boolean_T ) localMode [ 3UL ] && ( boolean_T ) localMode [ 2UL ] ) && ! ( (
boolean_T ) localMode [ 1UL ] || ( boolean_T ) localMode [ 0UL ] ) ? (
boolean_T ) localMode [ 8UL ] ? 1.0 : 0.0 : 1.0 ) != 0.0 ; t2 = ( ! ( (
boolean_T ) localMode [ 3UL ] && ( boolean_T ) localMode [ 2UL ] ) && ! ( (
boolean_T ) localMode [ 1UL ] || ( boolean_T ) localMode [ 0UL ] ) && ( (
boolean_T ) localMode [ 5UL ] && ( boolean_T ) localMode [ 4UL ] ) ? (
boolean_T ) localMode [ 6UL ] ? 1.0 : 0.0 : 1.0 ) != 0.0 ; local0 . mX [ 0UL
] = ( int32_T ) t2 ; local0 . mX [ 1UL ] = ( int32_T ) t1 ; ( void ) ds ; (
void ) in ; return 0 ; } static int32_T stub_method ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) { ( void ) ds
; ( void ) in ; ( void ) out ; return 0 ; } static NeDsMethodOutput *
ds_output_s ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mS .
mN = 16 ; out -> mS . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( int32_T ) , 16 ) ; return out ; } static NeDsMethodOutput *
ds_output_m_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mM_P .
mNumCol = 16 ; out -> mM_P . mNumRow = 16 ; out -> mM_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 17 ) ; out -> mM_P
. mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 2 ) ; return out ; } static NeDsMethodOutput * ds_output_m ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mM . mN = 2 ; out -> mM . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 2 ) ;
return out ; } static NeDsMethodOutput * ds_output_vmm ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mVMM . mN = 2 ; out -> mVMM . mX
= ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T )
, 2 ) ; return out ; } static NeDsMethodOutput * ds_output_dxm_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXM_P . mNumCol = 16 ; out ->
mDXM_P . mNumRow = 2 ; out -> mDXM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 17 ) ; out -> mDXM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxm ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXM . mN = 0 ; out -> mDXM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dum_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUM_P . mNumCol = 0 ; out ->
mDUM_P . mNumRow = 2 ; out -> mDUM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mDUM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dum ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUM . mN = 0 ; out -> mDUM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dtm_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTM_P . mNumCol = 1 ; out ->
mDTM_P . mNumRow = 2 ; out -> mDTM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dtm ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTM . mN = 0 ; out -> mDTM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_a_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mA_P . mNumCol = 16 ; out ->
mA_P . mNumRow = 16 ; out -> mA_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 17 ) ; out -> mA_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 35 ) ;
return out ; } static NeDsMethodOutput * ds_output_a ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mA . mN = 35 ; out -> mA . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 35 ) ; return out
; } static NeDsMethodOutput * ds_output_b_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mB_P . mNumCol = 0 ; out -> mB_P . mNumRow
= 16 ; out -> mB_P . mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( int32_T ) , 1 ) ; out -> mB_P . mIr = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_b ( const NeDynamicSystem * ds , NeAllocator *
allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput
* ) allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ;
out -> mB . mN = 0 ; out -> mB . mX = ( real_T * ) allocator -> mCallocFcn (
allocator , sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_c_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mC_P .
mNumCol = 1 ; out -> mC_P . mNumRow = 16 ; out -> mC_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mC_P
. mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_c ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mC . mN = 0 ; out -> mC . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_f ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mF . mN = 16 ; out -> mF . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 16 ) ; return out
; } static NeDsMethodOutput * ds_output_vmf ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mVMF . mN = 16 ; out -> mVMF . mX = (
boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) , 16
) ; return out ; } static NeDsMethodOutput * ds_output_slf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSLF . mN = 16 ; out -> mSLF .
mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T
) , 16 ) ; return out ; } static NeDsMethodOutput * ds_output_dxf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF_P . mNumCol = 16 ; out ->
mDXF_P . mNumRow = 16 ; out -> mDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 17 ) ; out -> mDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF . mN = 2 ; out -> mDXF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 2 )
; return out ; } static NeDsMethodOutput * ds_output_duf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF_P . mNumCol = 0 ; out ->
mDUF_P . mNumRow = 16 ; out -> mDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_duf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF . mN = 0 ; out -> mDUF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dtf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF_P . mNumCol = 1 ; out ->
mDTF_P . mNumRow = 16 ; out -> mDTF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ;
return out ; } static NeDsMethodOutput * ds_output_dtf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF . mN = 1 ; out -> mDTF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 1 )
; return out ; } static NeDsMethodOutput * ds_output_ddf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF_P . mNumCol = 0 ; out ->
mDDF_P . mNumRow = 16 ; out -> mDDF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mDDF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_ddf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF . mN = 0 ; out -> mDDF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_tduf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDUF_P . mNumCol = 0 ; out ->
mTDUF_P . mNumRow = 16 ; out -> mTDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mTDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_tdxf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDXF_P . mNumCol = 16 ; out ->
mTDXF_P . mNumRow = 16 ; out -> mTDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 17 ) ; out -> mTDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 39 ) ;
return out ; } static NeDsMethodOutput * ds_output_y ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mY . mN = 1 ; out -> mY . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 1 ) ; return out ;
} static NeDsMethodOutput * ds_output_dxy_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY_P . mNumCol = 16 ; out -> mDXY_P .
mNumRow = 1 ; out -> mDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 17 ) ; out -> mDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; return out ;
} static NeDsMethodOutput * ds_output_dxy ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY . mN = 1 ; out -> mDXY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 1 ) ; return
out ; } static NeDsMethodOutput * ds_output_duy_p ( const NeDynamicSystem *
ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUY_P . mNumCol = 0 ; out -> mDUY_P .
mNumRow = 1 ; out -> mDUY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 1 ) ; out -> mDUY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_duy ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUY . mN = 0 ; out -> mDUY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_dty_p ( const NeDynamicSystem *
ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTY_P . mNumCol = 1 ; out -> mDTY_P .
mNumRow = 1 ; out -> mDTY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dty ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTY . mN = 0 ; out -> mDTY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_mode ( const NeDynamicSystem * ds
, NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mMODE . mN = 10 ; out -> mMODE . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 10 ) ;
return out ; } static NeDsMethodOutput * ds_output_zc ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mZC . mN = 11 ; out -> mZC . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 11 ) ; return
out ; } static NeDsMethodOutput * ds_output_cache ( const NeDynamicSystem *
ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mCACHE . mN = 0 ; out -> mCACHE . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_update_r ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mUPDATE_R . mN = 0 ; out ->
mUPDATE_R . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_update_i
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mUPDATE_I . mN = 0 ;
out -> mUPDATE_I . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_sfo ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFO .
mN = 0 ; out -> mSFO . mX = ( real_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_sfp ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFP .
mN = 0 ; out -> mSFP . mX = ( real_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_init_r ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mINIT_R . mN = 0 ; out -> mINIT_R . mX = ( real_T * ) allocator -> mCallocFcn
( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_init_i ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mINIT_I . mN = 0 ; out -> mINIT_I . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_r ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mR . mN = 16 ; out -> mR . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 16 ) ; return out
; } static NeDsMethodOutput * ds_output_log ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mLOG . mN = 0 ; out -> mLOG . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_assert ( const NeDynamicSystem *
ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mASSERT . mN = 2 ; out -> mASSERT . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ;
return out ; } static NeDsMethodOutput * ds_output_del_t ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_T . mN = 0 ; out -> mDEL_T
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_v ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V . mN = 0 ; out -> mDEL_V
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_v0 ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V0 . mN = 0 ; out ->
mDEL_V0 . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_tmax
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_TMAX . mN = 0 ;
out -> mDEL_TMAX . mX = ( real_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_dxdelt_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT_P . mNumCol = 16 ; out -> mDXDELT_P . mNumRow = 0 ; out -> mDXDELT_P
. mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 17 ) ; out -> mDXDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_dxdelt ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT . mN = 0 ; out -> mDXDELT . mX = ( real_T * ) allocator -> mCallocFcn
( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_dudelt_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUDELT_P . mNumCol = 0 ; out -> mDUDELT_P
. mNumRow = 0 ; out -> mDUDELT_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mDUDELT_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dudelt ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUDELT . mN = 0 ; out ->
mDUDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt_p
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT_P . mNumCol =
1 ; out -> mDTDELT_P . mNumRow = 0 ; out -> mDTDELT_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out ->
mDTDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT . mN = 0 ; out
-> mDTDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static void release_reference (
NeDynamicSystem * ds ) { _NeDynamicSystem * _ds ; _ds = ( _NeDynamicSystem *
) ds ; if ( -- _ds -> mRefCnt == 0 ) { _ds -> mAlloc . mFreeFcn ( & _ds ->
mAlloc , _ds ) ; } } static void get_reference ( NeDynamicSystem * ds ) {
_NeDynamicSystem * _ds ; _ds = ( _NeDynamicSystem * ) ds ; ++ _ds -> mRefCnt
; } NeDynamicSystem * ssp2_3b3f044c_1_dae_ds ( NeAllocator * allocator ,
const void * params ) { NeDynamicSystem * ds ; _NeDynamicSystem * _ds ;
static NeDsIoInfo output_info [ 1 ] ; ( void ) params ; _ds = (
_NeDynamicSystem * ) allocator -> mCallocFcn ( allocator , sizeof (
_NeDynamicSystem ) , 1 ) ; _ds -> mAlloc = * allocator ; _ds -> mRefCnt = 1 ;
ds = & _ds -> mBase ; ds -> mNumVariables = 16 ; ds ->
mNumDiscreteRealVariables = 0 ; ds -> mNumDifferentialVariables = 2 ; ds ->
mNumEquations = 16 ; ds -> mNumModes = 10 ; ds -> mNumMajorModes = 0 ; ds ->
mNumCache = 0 ; ds -> mNumZcs = 11 ; ds -> mNumAsserts = 2 ; ds ->
mNumAssertRanges = 2 ; ds -> mNumRanges = 11 ; ds -> mNumEquationRanges = 13
; ds -> mNumFundamentalSamples = 0 ; ds -> mNumDelays = 0 ; ds ->
mIsOutputLinear = 1 ; ds -> mNumIo [ NE_INPUT_IO_TYPE ] = 0 ; ds -> mNumIo [
NE_OUTPUT_IO_TYPE ] = 1 ; output_info [ 0 ] . mIdentifier =
"ssp2/Voltage Sensor_" ; output_info [ 0 ] . mM = 1 ; output_info [ 0 ] . mN
= 1 ; output_info [ 0 ] . mName = "Voltage_Sensor.V" ; output_info [ 0 ] .
mUnit = "V" ; ds -> mIo [ NE_OUTPUT_IO_TYPE ] = output_info ; ds ->
mReleaseReference = release_reference ; ds -> mGetReference = get_reference ;
ds -> mMethods [ NE_DS_METHOD_S ] = ds_s ; ds -> mMakeOutput [ NE_DS_METHOD_S
] = ds_output_s ; ds -> mMethods [ NE_DS_METHOD_M_P ] = ds_m_p ; ds ->
mMakeOutput [ NE_DS_METHOD_M_P ] = ds_output_m_p ; ds -> mMethods [
NE_DS_METHOD_M ] = ds_m ; ds -> mMakeOutput [ NE_DS_METHOD_M ] = ds_output_m
; ds -> mMethods [ NE_DS_METHOD_VMM ] = ds_vmm ; ds -> mMakeOutput [
NE_DS_METHOD_VMM ] = ds_output_vmm ; ds -> mMethods [ NE_DS_METHOD_DXM_P ] =
ds_dxm_p ; ds -> mMakeOutput [ NE_DS_METHOD_DXM_P ] = ds_output_dxm_p ; ds ->
mMethods [ NE_DS_METHOD_DXM ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DXM ] = ds_output_dxm ; ds -> mMethods [ NE_DS_METHOD_DUM_P ] =
ds_dum_p ; ds -> mMakeOutput [ NE_DS_METHOD_DUM_P ] = ds_output_dum_p ; ds ->
mMethods [ NE_DS_METHOD_DUM ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DUM ] = ds_output_dum ; ds -> mMethods [ NE_DS_METHOD_DTM_P ] =
ds_dtm_p ; ds -> mMakeOutput [ NE_DS_METHOD_DTM_P ] = ds_output_dtm_p ; ds ->
mMethods [ NE_DS_METHOD_DTM ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DTM ] = ds_output_dtm ; ds -> mMethods [ NE_DS_METHOD_A_P ] =
ds_a_p ; ds -> mMakeOutput [ NE_DS_METHOD_A_P ] = ds_output_a_p ; ds ->
mMethods [ NE_DS_METHOD_A ] = ds_a ; ds -> mMakeOutput [ NE_DS_METHOD_A ] =
ds_output_a ; ds -> mMethods [ NE_DS_METHOD_B_P ] = ds_b_p ; ds ->
mMakeOutput [ NE_DS_METHOD_B_P ] = ds_output_b_p ; ds -> mMethods [
NE_DS_METHOD_B ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_B ] =
ds_output_b ; ds -> mMethods [ NE_DS_METHOD_C_P ] = ds_c_p ; ds ->
mMakeOutput [ NE_DS_METHOD_C_P ] = ds_output_c_p ; ds -> mMethods [
NE_DS_METHOD_C ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_C ] =
ds_output_c ; ds -> mMethods [ NE_DS_METHOD_F ] = ds_f ; ds -> mMakeOutput [
NE_DS_METHOD_F ] = ds_output_f ; ds -> mMethods [ NE_DS_METHOD_VMF ] = ds_vmf
; ds -> mMakeOutput [ NE_DS_METHOD_VMF ] = ds_output_vmf ; ds -> mMethods [
NE_DS_METHOD_SLF ] = ds_slf ; ds -> mMakeOutput [ NE_DS_METHOD_SLF ] =
ds_output_slf ; ds -> mMethods [ NE_DS_METHOD_DXF_P ] = ds_dxf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DXF_P ] = ds_output_dxf_p ; ds -> mMethods [
NE_DS_METHOD_DXF ] = ds_dxf ; ds -> mMakeOutput [ NE_DS_METHOD_DXF ] =
ds_output_dxf ; ds -> mMethods [ NE_DS_METHOD_DUF_P ] = ds_duf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DUF_P ] = ds_output_duf_p ; ds -> mMethods [
NE_DS_METHOD_DUF ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DUF ] =
ds_output_duf ; ds -> mMethods [ NE_DS_METHOD_DTF_P ] = ds_dtf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DTF_P ] = ds_output_dtf_p ; ds -> mMethods [
NE_DS_METHOD_DTF ] = ds_dtf ; ds -> mMakeOutput [ NE_DS_METHOD_DTF ] =
ds_output_dtf ; ds -> mMethods [ NE_DS_METHOD_DDF_P ] = ds_ddf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DDF_P ] = ds_output_ddf_p ; ds -> mMethods [
NE_DS_METHOD_DDF ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DDF ] =
ds_output_ddf ; ds -> mMethods [ NE_DS_METHOD_TDUF_P ] = ds_tduf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_TDUF_P ] = ds_output_tduf_p ; ds -> mMethods [
NE_DS_METHOD_TDXF_P ] = ds_tdxf_p ; ds -> mMakeOutput [ NE_DS_METHOD_TDXF_P ]
= ds_output_tdxf_p ; ds -> mMethods [ NE_DS_METHOD_Y ] = ds_y ; ds ->
mMakeOutput [ NE_DS_METHOD_Y ] = ds_output_y ; ds -> mMethods [
NE_DS_METHOD_DXY_P ] = ds_dxy_p ; ds -> mMakeOutput [ NE_DS_METHOD_DXY_P ] =
ds_output_dxy_p ; ds -> mMethods [ NE_DS_METHOD_DXY ] = ds_dxy ; ds ->
mMakeOutput [ NE_DS_METHOD_DXY ] = ds_output_dxy ; ds -> mMethods [
NE_DS_METHOD_DUY_P ] = ds_duy_p ; ds -> mMakeOutput [ NE_DS_METHOD_DUY_P ] =
ds_output_duy_p ; ds -> mMethods [ NE_DS_METHOD_DUY ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_DUY ] = ds_output_duy ; ds -> mMethods [
NE_DS_METHOD_DTY_P ] = ds_dty_p ; ds -> mMakeOutput [ NE_DS_METHOD_DTY_P ] =
ds_output_dty_p ; ds -> mMethods [ NE_DS_METHOD_DTY ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_DTY ] = ds_output_dty ; ds -> mMethods [
NE_DS_METHOD_MODE ] = ds_mode ; ds -> mMakeOutput [ NE_DS_METHOD_MODE ] =
ds_output_mode ; ds -> mMethods [ NE_DS_METHOD_ZC ] = ds_zc ; ds ->
mMakeOutput [ NE_DS_METHOD_ZC ] = ds_output_zc ; ds -> mMethods [
NE_DS_METHOD_CACHE ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_CACHE ]
= ds_output_cache ; ds -> mMethods [ NE_DS_METHOD_UPDATE_R ] = stub_method ;
ds -> mMakeOutput [ NE_DS_METHOD_UPDATE_R ] = ds_output_update_r ; ds ->
mMethods [ NE_DS_METHOD_UPDATE_I ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_UPDATE_I ] = ds_output_update_i ; ds -> mMethods [
NE_DS_METHOD_SFO ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_SFO ] =
ds_output_sfo ; ds -> mMethods [ NE_DS_METHOD_SFP ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_SFP ] = ds_output_sfp ; ds -> mMethods [
NE_DS_METHOD_INIT_R ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_INIT_R
] = ds_output_init_r ; ds -> mMethods [ NE_DS_METHOD_INIT_I ] = stub_method ;
ds -> mMakeOutput [ NE_DS_METHOD_INIT_I ] = ds_output_init_i ; ds -> mMethods
[ NE_DS_METHOD_R ] = ds_r ; ds -> mMakeOutput [ NE_DS_METHOD_R ] =
ds_output_r ; ds -> mMethods [ NE_DS_METHOD_LOG ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_LOG ] = ds_output_log ; ds -> mMethods [
NE_DS_METHOD_ASSERT ] = ds_assert ; ds -> mMakeOutput [ NE_DS_METHOD_ASSERT ]
= ds_output_assert ; ds -> mMethods [ NE_DS_METHOD_DEL_T ] = stub_method ; ds
-> mMakeOutput [ NE_DS_METHOD_DEL_T ] = ds_output_del_t ; ds -> mMethods [
NE_DS_METHOD_DEL_V ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DEL_V ]
= ds_output_del_v ; ds -> mMethods [ NE_DS_METHOD_DEL_V0 ] = stub_method ; ds
-> mMakeOutput [ NE_DS_METHOD_DEL_V0 ] = ds_output_del_v0 ; ds -> mMethods [
NE_DS_METHOD_DEL_TMAX ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DEL_TMAX ] = ds_output_del_tmax ; ds -> mMethods [
NE_DS_METHOD_DXDELT_P ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DXDELT_P ] = ds_output_dxdelt_p ; ds -> mMethods [
NE_DS_METHOD_DXDELT ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DXDELT
] = ds_output_dxdelt ; ds -> mMethods [ NE_DS_METHOD_DUDELT_P ] = stub_method
; ds -> mMakeOutput [ NE_DS_METHOD_DUDELT_P ] = ds_output_dudelt_p ; ds ->
mMethods [ NE_DS_METHOD_DUDELT ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DUDELT ] = ds_output_dudelt ; ds -> mMethods [
NE_DS_METHOD_DTDELT_P ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DTDELT_P ] = ds_output_dtdelt_p ; ds -> mMethods [
NE_DS_METHOD_DTDELT ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DTDELT
] = ds_output_dtdelt ; ds -> mEquationData = s_equation_data ; ds ->
mVariableData = s_variable_data ; ds -> mDiscreteData = s_discrete_data ; ds
-> mMajorModeData = s_major_mode_data ; ds -> mZCData = s_zc_data ; ds ->
mRanges = s_range ; ds -> mAssertData = s_assert_data ; ds -> mAssertRanges =
s_assert_range ; ds -> mEquationRanges = s_equation_range ; return (
NeDynamicSystem * ) _ds ; }
