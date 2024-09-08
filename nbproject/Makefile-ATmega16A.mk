#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-ATmega16A.mk)" "nbproject/Makefile-local-ATmega16A.mk"
include nbproject/Makefile-local-ATmega16A.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=ATmega16A
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/app.c src/userSystem.c src/configuration.c src/network.c src/dataTiming.c src/Requests.c src/PowerOn.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/app.o ${OBJECTDIR}/src/userSystem.o ${OBJECTDIR}/src/configuration.o ${OBJECTDIR}/src/network.o ${OBJECTDIR}/src/dataTiming.o ${OBJECTDIR}/src/Requests.o ${OBJECTDIR}/src/PowerOn.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/app.o.d ${OBJECTDIR}/src/userSystem.o.d ${OBJECTDIR}/src/configuration.o.d ${OBJECTDIR}/src/network.o.d ${OBJECTDIR}/src/dataTiming.o.d ${OBJECTDIR}/src/Requests.o.d ${OBJECTDIR}/src/PowerOn.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/app.o ${OBJECTDIR}/src/userSystem.o ${OBJECTDIR}/src/configuration.o ${OBJECTDIR}/src/network.o ${OBJECTDIR}/src/dataTiming.o ${OBJECTDIR}/src/Requests.o ${OBJECTDIR}/src/PowerOn.o

# Source Files
SOURCEFILES=src/app.c src/userSystem.c src/configuration.c src/network.c src/dataTiming.c src/Requests.c src/PowerOn.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega16a"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-ATmega16A.mk ${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega16A
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/app.o: src/app.c  .generated_files/flags/ATmega16A/17f9c30fb68b54520443e24ea38294e5de869490 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/app.o.d 
	@${RM} ${OBJECTDIR}/src/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/app.o.d" -MT "${OBJECTDIR}/src/app.o.d" -MT ${OBJECTDIR}/src/app.o  -o ${OBJECTDIR}/src/app.o src/app.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem.o: src/userSystem.c  .generated_files/flags/ATmega16A/df855ff266739af78dedd91a0f7bfb082cacab22 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/userSystem.o.d" -MT "${OBJECTDIR}/src/userSystem.o.d" -MT ${OBJECTDIR}/src/userSystem.o  -o ${OBJECTDIR}/src/userSystem.o src/userSystem.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration.o: src/configuration.c  .generated_files/flags/ATmega16A/9aa970c184026613c121bed010904869cc49309d .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration.o.d 
	@${RM} ${OBJECTDIR}/src/configuration.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/configuration.o.d" -MT "${OBJECTDIR}/src/configuration.o.d" -MT ${OBJECTDIR}/src/configuration.o  -o ${OBJECTDIR}/src/configuration.o src/configuration.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/network.o: src/network.c  .generated_files/flags/ATmega16A/c0938256496d23c2c5852df6231850eb08f85b93 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/network.o.d 
	@${RM} ${OBJECTDIR}/src/network.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/network.o.d" -MT "${OBJECTDIR}/src/network.o.d" -MT ${OBJECTDIR}/src/network.o  -o ${OBJECTDIR}/src/network.o src/network.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/dataTiming.o: src/dataTiming.c  .generated_files/flags/ATmega16A/defe516c50610d97ca10889a410289167a90a4b9 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/dataTiming.o.d 
	@${RM} ${OBJECTDIR}/src/dataTiming.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/dataTiming.o.d" -MT "${OBJECTDIR}/src/dataTiming.o.d" -MT ${OBJECTDIR}/src/dataTiming.o  -o ${OBJECTDIR}/src/dataTiming.o src/dataTiming.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Requests.o: src/Requests.c  .generated_files/flags/ATmega16A/4be92dde1f058813d4327245016505439f7fe2e .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Requests.o.d 
	@${RM} ${OBJECTDIR}/src/Requests.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/Requests.o.d" -MT "${OBJECTDIR}/src/Requests.o.d" -MT ${OBJECTDIR}/src/Requests.o  -o ${OBJECTDIR}/src/Requests.o src/Requests.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PowerOn.o: src/PowerOn.c  .generated_files/flags/ATmega16A/f9ef8a4b4cf6b7f2d50d75fd281c0276bb6b3446 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PowerOn.o.d 
	@${RM} ${OBJECTDIR}/src/PowerOn.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/PowerOn.o.d" -MT "${OBJECTDIR}/src/PowerOn.o.d" -MT ${OBJECTDIR}/src/PowerOn.o  -o ${OBJECTDIR}/src/PowerOn.o src/PowerOn.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/app.o: src/app.c  .generated_files/flags/ATmega16A/eee23d8807d2e3eaeb94ed69ea3a21a70d044d81 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/app.o.d 
	@${RM} ${OBJECTDIR}/src/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/app.o.d" -MT "${OBJECTDIR}/src/app.o.d" -MT ${OBJECTDIR}/src/app.o  -o ${OBJECTDIR}/src/app.o src/app.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem.o: src/userSystem.c  .generated_files/flags/ATmega16A/d1915f517718787c540ccfb9c7bfc1aa5562e8f2 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/userSystem.o.d" -MT "${OBJECTDIR}/src/userSystem.o.d" -MT ${OBJECTDIR}/src/userSystem.o  -o ${OBJECTDIR}/src/userSystem.o src/userSystem.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration.o: src/configuration.c  .generated_files/flags/ATmega16A/da6df62e2268db1360af82f7d5918175c3bfe039 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration.o.d 
	@${RM} ${OBJECTDIR}/src/configuration.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/configuration.o.d" -MT "${OBJECTDIR}/src/configuration.o.d" -MT ${OBJECTDIR}/src/configuration.o  -o ${OBJECTDIR}/src/configuration.o src/configuration.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/network.o: src/network.c  .generated_files/flags/ATmega16A/dd0638e4277bf6a9521e2f39ba96d7d48801756 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/network.o.d 
	@${RM} ${OBJECTDIR}/src/network.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/network.o.d" -MT "${OBJECTDIR}/src/network.o.d" -MT ${OBJECTDIR}/src/network.o  -o ${OBJECTDIR}/src/network.o src/network.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/dataTiming.o: src/dataTiming.c  .generated_files/flags/ATmega16A/56f4eef9cc446e3d67d65bbe27fd0067e018bc90 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/dataTiming.o.d 
	@${RM} ${OBJECTDIR}/src/dataTiming.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/dataTiming.o.d" -MT "${OBJECTDIR}/src/dataTiming.o.d" -MT ${OBJECTDIR}/src/dataTiming.o  -o ${OBJECTDIR}/src/dataTiming.o src/dataTiming.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Requests.o: src/Requests.c  .generated_files/flags/ATmega16A/a208d43f25a7ba98ed2b06d8376821008beccc3a .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Requests.o.d 
	@${RM} ${OBJECTDIR}/src/Requests.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/Requests.o.d" -MT "${OBJECTDIR}/src/Requests.o.d" -MT ${OBJECTDIR}/src/Requests.o  -o ${OBJECTDIR}/src/Requests.o src/Requests.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PowerOn.o: src/PowerOn.c  .generated_files/flags/ATmega16A/5ec944200c3233eced7beda15dd95f5d9d20db45 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PowerOn.o.d 
	@${RM} ${OBJECTDIR}/src/PowerOn.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/src/PowerOn.o.d" -MT "${OBJECTDIR}/src/PowerOn.o.d" -MT ${OBJECTDIR}/src/PowerOn.o  -o ${OBJECTDIR}/src/PowerOn.o src/PowerOn.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/mega2.X.a  
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega16a ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\NurseDisplay.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    lib\mega2.X.a  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/mega2.X.a 
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega16a ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\NurseDisplay.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    lib\mega2.X.a  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/NurseDisplay.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
