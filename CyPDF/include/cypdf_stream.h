#ifndef CYPDF_STREAM_H
#define CYPDF_STREAM_H






typedef struct _CYPDF_Stream_Obj {
    CYPDF_Obj_Header        header;
    CYPDF_Dict_Obj          dict;
    CYPDF_BYTE*             value;
    CYPDF_SIZE              size;
} CYPDF_Stream_Obj;



#endif /* CYPDF_STREAM_H */