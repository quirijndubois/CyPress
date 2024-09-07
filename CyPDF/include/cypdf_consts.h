#ifndef CYPDF_CONSTS_H
#define CYPDF_CONSTS_H


#include <math.h>

#include "cypdf_types.h"



/* CYPDF ASCII white-space characters */
#define CYPDF_ASCII_NUL             '\0'        /* the null character, in hex: 0x00 */
#define CYPDF_ASCII_HT              '\t'        /* the tab character, in hex: 0x09 */
#define CYPDF_ASCII_LF              '\n'        /* the line feed character, in hex: 0x0A */
#define CYPDF_ASCII_FF              '\f'        /* the form feed character, in hex: 0x0C */
#define CYPDF_ASCII_CR              '\r'        /* the carriage return character, in hex: 0x0D */
#define CYPDF_ASCII_SP              ' '         /* the space character, in hex: 0x20 */


/* CYPDF new line string */
#define CYPDF_NEW_LINE              "\x0D\x0A"  /* Carriage return followed by line feed. */


/* CYPDF boolean values */
#define CYPDF_TRUE                  1
#define CYPDF_FALSE                 0


/* CYPDF limits */
#define CYPDF_INDIRECT_OBJ_MAX      8388607     /* 2^23 - 1 */
#define CYPDF_OGEN_MAX              65535       /* 2^16 - 1 */


/* Page sizes (UU: User Unit) */
#define CYPDF_INCH_TO_UU(x)         (72 * (x))
#define CYPDF_UU_TO_INCH(x)         ((x) / 72)
#define CYPDF_MM_TO_UU(x)           (72 / 25.4 * (x))
#define CYPDF_UU_TO_MM(x)           (25.4 / 72 * (x))

#define CYPDF_A1_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(594)))
#define CYPDF_A1_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(841)))
#define CYPDF_A1_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A1_WIDTH), (CYPDF_A1_HEIGHT) })

#define CYPDF_A2_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(420)))
#define CYPDF_A2_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(594)))
#define CYPDF_A2_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A2_WIDTH), (CYPDF_A2_HEIGHT) })

#define CYPDF_A3_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(297)))
#define CYPDF_A3_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(420)))
#define CYPDF_A3_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A3_WIDTH), (CYPDF_A3_HEIGHT) })

#define CYPDF_A4_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(210)))
#define CYPDF_A4_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(297)))
#define CYPDF_A4_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A4_WIDTH), (CYPDF_A4_HEIGHT) })

#define CYPDF_A5_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(148)))
#define CYPDF_A5_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(210)))
#define CYPDF_A5_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A5_WIDTH), (CYPDF_A5_HEIGHT) })

#define CYPDF_A6_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(105)))
#define CYPDF_A6_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(148)))
#define CYPDF_A6_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A6_WIDTH), (CYPDF_A6_HEIGHT) })

#define CYPDF_A7_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(74)))
#define CYPDF_A7_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(105)))
#define CYPDF_A7_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A7_WIDTH), (CYPDF_A7_HEIGHT) })

#define CYPDF_A8_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(52)))
#define CYPDF_A8_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(74)))
#define CYPDF_A8_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A8_WIDTH), (CYPDF_A8_HEIGHT) })

#define CYPDF_A9_WIDTH              ((CYPDF_REAL)round(CYPDF_MM_TO_UU(37)))
#define CYPDF_A9_HEIGHT             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(52)))
#define CYPDF_A9_MEDIABOX           ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A9_WIDTH), (CYPDF_A9_HEIGHT) })

#define CYPDF_A10_WIDTH             ((CYPDF_REAL)round(CYPDF_MM_TO_UU(26)))
#define CYPDF_A10_HEIGHT            ((CYPDF_REAL)round(CYPDF_MM_TO_UU(37)))
#define CYPDF_A10_MEDIABOX          ((CYPDF_Rect){ 0.0, 0.0, (CYPDF_A10_WIDTH), (CYPDF_A10_HEIGHT) })



#endif /* CYPDF_CONSTS_H */
