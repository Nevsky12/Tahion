#pragma once


#define CAT_(a, b) a ## b
#define CAT(a, b) CAT_(a, b)

#define CAT3_(a, b, c) a ## b ## c
#define CAT3(a, b, c) CAT3_(a, b, c)

#define CAT4_(a, b, c, d) a ## b ## c ## d
#define CAT4(a, b, c, d) CAT4_(a, b, c, d)

#define CAT5_(a, b, c, d, e) a ## b ## c ## d ## e
#define CAT5(a, b, c, d, e) CAT4_(a, b, c, d, e)


#define FILE_UNIQUE(x) CAT(x, __LINE__)


#define CAPITALIZE(name) CAPITALIZE_##name


#define STRINGIFY(content) #content

#define STRING_QUOTE(content) STRINGIFY(content)
