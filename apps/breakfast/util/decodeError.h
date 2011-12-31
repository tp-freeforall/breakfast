#ifndef decode_error_h
#define decode_error_h
const char* error_strings[] = {
    "SUCCESS",
    "FAIL",
    "ESIZE",
    "ECANCEL",
    "EOFF",
    "EBUSY",
    "EINVAL",
    "ERETRY",
    "ERESERVE",
    "EALREADY",
    "ENOMEM",
    "ENOACK",
    "ELAST",
};

const char* decodeError(error_t err){
  return error_strings[err];
}
#endif
