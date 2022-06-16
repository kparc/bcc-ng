//! type system

#include"_.h"             //!< core macros and types

//! type system
#define KC 1ULL           //!< char
#define KH 2ULL           //!< short
#define KI 3ULL           //!< int
#define KJ 4ULL           //!< long
#define KE 5ULL           //!< float
#define KF 6ULL           //!< double
#define KS 7ULL           //!< symbol

#define ptr(x) (*(S*)&x)  //!< cast x to an S lvalue

//! x y z f r             ..are classic locals:
#define xi I(x)           //!< cast x to int32 atom
#define xj (J)(x)         //!< cast x to int64 atom
#define xf *(F*)&x        //!< retrieve double atom
//! vector preamble is mturnnnn:
#define xm xG[-8]         //!< (m)alloc bucket id
#define xt xG[-5]         //!< (t)ype id
#define xu xG[-6]         //!< list attrib(u)tes
#define xr xG[-7]         //!< (r)eference count
#define xn xI[-1]         //!< vector le(n)gth
//! vector accessors and casts:
#define xI ((I*)x)        //!< cast to list of ints
#define xJ ((J*)x)        //!<           ..of longs
#define xF ((F*)x)        //!<         ..of doubles
#define xK ((K*)x)        //!<        ..of sublists
#define Xg ((S)x)[i]      //!<          ..to string
#define Xi xI[i]          //!<      i'th int32 of x
#define Xj xJ[i]          //!<      i'th int64 of x
#define Xk xK[i]          //!<    i'th sublist of x
#define Xx xK[i]          //!<  i'th subvector of x
#define xx xK[0]          //!<     1st element of x
#define xy xK[1]          //!<                ..2nd
#define xz xK[2]          //!<                ..3rd
#define xxu ptr(xx)[-6]   //!< attrs of 1st element
#define xyu ptr(xy)[-6]   //!< attrs of 2st element
#define xG  ptr(x)        //!< cast x to byte list

#define yi I(y)           //!< cast y to int32 atom
#define yj (J)(y)         //!< cast y to int64 atom
#define yf *(F*)&y        //!< retrieve double atom
#define ym yG[-8]         //!< (m)alloc bucket id
#define yt yG[-5]         //!< (t)ype id
#define yu yG[-6]         //!< list attrib(u)tes
#define yr yG[-7]         //!< (r)eference count
#define yn yI[-1]         //!< vector le(n)gth
#define yI ((I*)y)        //!< cast to list of ints
#define yF ((F*)y)        //!<         ..of doubles
#define yK ((K*)y)        //!<        ..of sublists
#define Yg ((S)y)[i]      //!<          ..to string
#define Yi yI[i]          //!<      i'th int32 of y
#define Yj yJ[i]          //!<      i'th int64 of y
#define Yk yK[i]          //!<  i'th subvector of y
#define yx yK[0]          //!<     1st element of y
#define yy yK[1]          //!<                ..2nd
#define yz yK[2]          //!<                ..3rd
#define yxu ptr(yx)[-6]   //!< attrs of 1st element
#define yyu ptr(yy)[-6]   //!< attrs of 2st element
#define yG  ptr(y)

/*
#define ri I(r)           //!< cast r to int32 atom
#define rj (J)(r)         //!< cast r to int64 atom
#define rf *(F*)&r        //!< retrieve double atom
#define rm rG[-8]         //!< (m)alloc bucket id
#define rt rG[-5]         //!< (t)ype id
#define ru rG[-6]         //!< list attrib(u)tes
#define rr rG[-7]         //!< (r)eference count
#define rn rI[-1]         //!< vector le(n)gth
#define rI ((I*)r)        //!< cast to list of ints
#define rF ((F*)r)        //!<         ..of doubles
#define rK ((K*)r)        //!<        ..of sublists
#define Rg ((S)r)[i]      //!<          ..to string
#define Ri rI[i]          //!<      i'th int32 of r
#define Rj rJ[i]          //!<      i'th int64 of r
#define Rk rK[i]          //!<  i'th subvector of r
#define rx rK[0]          //!<     1st element of r
#define ry rK[1]          //!<                ..2nd
#define rz rK[2]          //!<                ..3rd
#define rxu ptr(rx)[-6]   //!< attrs of 1st element
#define ryu ptr(ry)[-6]   //!< attrs of 2st element
#define rG ptr(r)

#define zG ptr(z)
#define fG ptr(f)
*/
#define A(x) ({J _j=(J)(x);!_j||_j>>52?KF:15&_j>>48;})
#define Ax A(x)           //!< is x atom or vector?
#define Ay A(y)           //!< is y atom or vector?
#define Az A(z)           //!< is z atom or vector?
#define Ar A(r)           //!< is r atom or vector?

//:~
