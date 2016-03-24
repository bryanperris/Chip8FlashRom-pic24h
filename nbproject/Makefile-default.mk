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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=glcd.c graphics.c graphs.c PCD8544.c PIC24H.c text.c text_tiny.c unit_tests.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/glcd.o ${OBJECTDIR}/graphics.o ${OBJECTDIR}/graphs.o ${OBJECTDIR}/PCD8544.o ${OBJECTDIR}/PIC24H.o ${OBJECTDIR}/text.o ${OBJECTDIR}/text_tiny.o ${OBJECTDIR}/unit_tests.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/glcd.o.d ${OBJECTDIR}/graphics.o.d ${OBJECTDIR}/graphs.o.d ${OBJECTDIR}/PCD8544.o.d ${OBJECTDIR}/PIC24H.o.d ${OBJECTDIR}/text.o.d ${OBJECTDIR}/text_tiny.o.d ${OBJECTDIR}/unit_tests.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/glcd.o ${OBJECTDIR}/graphics.o ${OBJECTDIR}/graphs.o ${OBJECTDIR}/PCD8544.o ${OBJECTDIR}/PIC24H.o ${OBJECTDIR}/text.o ${OBJECTDIR}/text_tiny.o ${OBJECTDIR}/unit_tests.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=glcd.c graphics.c graphs.c PCD8544.c PIC24H.c text.c text_tiny.c unit_tests.c main.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ32GP202
MP_LINKER_FILE_OPTION=,--script=p24HJ32GP202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/glcd.o: glcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/glcd.o.d 
	@${RM} ${OBJECTDIR}/glcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  glcd.c  -o ${OBJECTDIR}/glcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/glcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/glcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/graphics.o: graphics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/graphics.o.d 
	@${RM} ${OBJECTDIR}/graphics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  graphics.c  -o ${OBJECTDIR}/graphics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/graphics.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/graphics.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/graphs.o: graphs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/graphs.o.d 
	@${RM} ${OBJECTDIR}/graphs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  graphs.c  -o ${OBJECTDIR}/graphs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/graphs.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/graphs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PCD8544.o: PCD8544.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PCD8544.o.d 
	@${RM} ${OBJECTDIR}/PCD8544.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PCD8544.c  -o ${OBJECTDIR}/PCD8544.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PCD8544.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/PCD8544.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PIC24H.o: PIC24H.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PIC24H.o.d 
	@${RM} ${OBJECTDIR}/PIC24H.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIC24H.c  -o ${OBJECTDIR}/PIC24H.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PIC24H.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/PIC24H.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/text.o: text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/text.o.d 
	@${RM} ${OBJECTDIR}/text.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  text.c  -o ${OBJECTDIR}/text.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/text.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/text.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/text_tiny.o: text_tiny.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/text_tiny.o.d 
	@${RM} ${OBJECTDIR}/text_tiny.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  text_tiny.c  -o ${OBJECTDIR}/text_tiny.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/text_tiny.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/text_tiny.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/unit_tests.o: unit_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/unit_tests.o.d 
	@${RM} ${OBJECTDIR}/unit_tests.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  unit_tests.c  -o ${OBJECTDIR}/unit_tests.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/unit_tests.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/unit_tests.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/glcd.o: glcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/glcd.o.d 
	@${RM} ${OBJECTDIR}/glcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  glcd.c  -o ${OBJECTDIR}/glcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/glcd.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/glcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/graphics.o: graphics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/graphics.o.d 
	@${RM} ${OBJECTDIR}/graphics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  graphics.c  -o ${OBJECTDIR}/graphics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/graphics.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/graphics.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/graphs.o: graphs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/graphs.o.d 
	@${RM} ${OBJECTDIR}/graphs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  graphs.c  -o ${OBJECTDIR}/graphs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/graphs.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/graphs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PCD8544.o: PCD8544.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PCD8544.o.d 
	@${RM} ${OBJECTDIR}/PCD8544.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PCD8544.c  -o ${OBJECTDIR}/PCD8544.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PCD8544.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/PCD8544.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/PIC24H.o: PIC24H.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PIC24H.o.d 
	@${RM} ${OBJECTDIR}/PIC24H.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIC24H.c  -o ${OBJECTDIR}/PIC24H.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PIC24H.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/PIC24H.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/text.o: text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/text.o.d 
	@${RM} ${OBJECTDIR}/text.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  text.c  -o ${OBJECTDIR}/text.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/text.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/text.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/text_tiny.o: text_tiny.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/text_tiny.o.d 
	@${RM} ${OBJECTDIR}/text_tiny.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  text_tiny.c  -o ${OBJECTDIR}/text_tiny.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/text_tiny.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/text_tiny.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/unit_tests.o: unit_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/unit_tests.o.d 
	@${RM} ${OBJECTDIR}/unit_tests.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  unit_tests.c  -o ${OBJECTDIR}/unit_tests.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/unit_tests.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/unit_tests.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/Program\ Files\ (x86)/Microchip/xc16/v1.26/lib/libc-elf.a C:/Program\ Files\ (x86)/Microchip/xc16/v1.26/lib/libpic30-elf.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "C:\Program Files (x86)\Microchip\xc16\v1.26\lib\libc-elf.a" "C:\Program Files (x86)\Microchip\xc16\v1.26\lib\libpic30-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/Program\ Files\ (x86)/Microchip/xc16/v1.26/lib/libc-elf.a C:/Program\ Files\ (x86)/Microchip/xc16/v1.26/lib/libpic30-elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "C:\Program Files (x86)\Microchip\xc16\v1.26\lib\libc-elf.a" "C:\Program Files (x86)\Microchip\xc16\v1.26\lib\libpic30-elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -relaxed-math -legacy-libc  -I"C:/Program Files (x86)/Microchip/xc16/v1.26/include" -I"C:/Program Files (x86)/Microchip/xc16/v1.26/support/generic/h" -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Chip8FlashRom.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
