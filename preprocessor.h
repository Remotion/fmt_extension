#pragma once
#ifndef PREPROCESSOR_RE_H_
#define PREPROCESSOR_RE_H_
//=================================================================================================
//  preprocessor.h
//  #include "preprocessor.h"
//  Created: 05.06.2018
//  Remotion (C) 2018 - All Rights Reserved
//=================================================================================================



/// Based on Boost preprocessor/variadic/size.hpp 

// PP_CAT macro concatenates its arguments after they have been expanded. 
// PP_CAT(x, PP_CAT(y, z)) // expands to xyz
#define PP_CAT(a, b) IMP_PP_CAT_I(a, b)

#if defined(_MSC_VER) && !defined(__clang__)
#  define IMP_PP_CAT_I(a, b) IMP_PP_CAT_II(~, a ## b)
#  define IMP_PP_CAT_II(p, res) res
#else
#  define IMP_PP_CAT_I(a, b) a ## b
#endif

// PP_VARIADIC_SIZE variadic macro expands to the size of the variadic data passed to it. 
#if defined(_MSC_VER) && !defined(__clang__)
#  define PP_VARIADIC_SIZE(...) PP_CAT(IMP_PP_VARIADIC_SIZE_I(__VA_ARGS__, 99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,),)
#else
#  define PP_VARIADIC_SIZE(...) IMP_PP_VARIADIC_SIZE_I(__VA_ARGS__, 99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,)
#endif
#define IMP_PP_VARIADIC_SIZE_I(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,e61,e62,e63,e64,e65,e66,e67,e68,e69,e70,e71,e72,e73,e74,e75,e76,e77,e78,e79,e80,e81,e82,e83,e84,e85,e86,e87,e88,e89,e90,e91,e92,e93,e94,e95,e96,e97,e98, size, ...) size



#define PP_ID(V)	V

#define ARGS_0(O) 
#define ARGS_1(O) O(a)
#define ARGS_2(O) O(a),O(b)
#define ARGS_3(O) O(a),O(b),O(c)
#define ARGS_4(O) O(a),O(b),O(c),O(d)
#define ARGS_5(O) O(a),O(b),O(c),O(d),O(e)
#define ARGS_6(O) O(a),O(b),O(c),O(d),O(e),O(f)
#define ARGS_7(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g)
#define ARGS_8(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h)
#define ARGS_9(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j)
#define ARGS_10(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k)
#define ARGS_11(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l)
#define ARGS_12(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m)
#define ARGS_13(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n)
#define ARGS_14(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p)
#define ARGS_15(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q)
#define ARGS_16(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r)
#define ARGS_17(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s)
#define ARGS_18(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s),O(t)
#define ARGS_19(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s),O(t),O(u)
#define ARGS_20(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s),O(t),O(u),O(v)
#define ARGS_21(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s),O(t),O(u),O(v),O(w)
#define ARGS_22(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s),O(t),O(u),O(v),O(w),O(x)
#define ARGS_23(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s),O(t),O(u),O(v),O(w),O(x),O(y)
#define ARGS_24(O) O(a),O(b),O(c),O(d),O(e),O(f),O(g),O(h),O(j),O(k),O(l),O(m),O(n),O(p),O(q),O(r),O(s),O(t),O(u),O(v),O(w),O(x),O(y),O(z)
#define ARGS_25(O) ARGS_24(O),O(A)
#define ARGS_26(O) ARGS_24(O),O(A),O(B)
#define ARGS_27(O) ARGS_24(O),O(A),O(B),O(C)
#define ARGS_28(O) ARGS_24(O),O(A),O(B),O(C),O(D)
#define ARGS_29(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E)
#define ARGS_30(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F)
#define ARGS_31(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G)
#define ARGS_32(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H)
#define ARGS_33(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J)
#define ARGS_34(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K)
#define ARGS_35(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L)
#define ARGS_36(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M)
#define ARGS_37(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N)
#define ARGS_38(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P)
#define ARGS_39(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q)
#define ARGS_40(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R)
#define ARGS_41(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R),O(S)
#define ARGS_42(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R),O(S),O(U)
#define ARGS_43(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R),O(S),O(U),O(V)
#define ARGS_44(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R),O(S),O(U),O(V),O(W)
#define ARGS_45(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R),O(S),O(U),O(V),O(W),O(X)
#define ARGS_46(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R),O(S),O(U),O(V),O(W),O(X),O(Y)
#define ARGS_47(O) ARGS_24(O),O(A),O(B),O(C),O(D),O(E),O(F),O(G),O(H),O(J),O(K),O(L),O(M),O(N),O(P),O(Q),O(R),O(S),O(U),O(V),O(W),O(X),O(Y),O(Z)
#define ARGS_48(O) ARGS_47(O),O(_a)
#define ARGS_49(O) ARGS_47(O),O(_a),O(_b)
#define ARGS_50(O) ARGS_47(O),O(_a),O(_b),O(_c)
#define ARGS_51(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d)
#define ARGS_52(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e)
#define ARGS_53(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f)
#define ARGS_54(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g)
#define ARGS_55(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h)
#define ARGS_56(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j)
#define ARGS_57(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k)
#define ARGS_58(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l)
#define ARGS_59(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m)
#define ARGS_60(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n)
#define ARGS_61(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p)
#define ARGS_62(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q)
#define ARGS_63(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r)
#define ARGS_64(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s)
#define ARGS_65(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s),O(_t)
#define ARGS_66(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s),O(_t),O(_u)
#define ARGS_67(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s),O(_t),O(_u),O(_v)
#define ARGS_68(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s),O(_t),O(_u),O(_v),O(_w)
#define ARGS_69(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s),O(_t),O(_u),O(_v),O(_w),O(_x)
#define ARGS_70(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s),O(_t),O(_u),O(_v),O(_w),O(_x),O(_y)
#define ARGS_71(O) ARGS_47(O),O(_a),O(_b),O(_c),O(_d),O(_e),O(_f),O(_g),O(_h),O(_j),O(_k),O(_l),O(_m),O(_n),O(_p),O(_q),O(_r),O(_s),O(_t),O(_u),O(_v),O(_w),O(_x),O(_y),O(_z)
#define ARGS_72(O) ARGS_71(O),O(_A)
#define ARGS_73(O) ARGS_71(O),O(_A),O(_B)
#define ARGS_74(O) ARGS_71(O),O(_A),O(_B),O(_C)
#define ARGS_75(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D)
#define ARGS_76(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E)
#define ARGS_77(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F)
#define ARGS_78(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G)
#define ARGS_79(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H)
#define ARGS_80(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J)
#define ARGS_81(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K)
#define ARGS_82(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L)
#define ARGS_83(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M)
#define ARGS_84(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N)
#define ARGS_85(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P)
#define ARGS_86(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q)
#define ARGS_87(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R)
#define ARGS_88(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R),O(_S)
#define ARGS_89(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R),O(_S),O(_U)
#define ARGS_90(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R),O(_S),O(_U),O(_V)
#define ARGS_91(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R),O(_S),O(_U),O(_V),O(_W)
#define ARGS_92(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R),O(_S),O(_U),O(_V),O(_W),O(_X)
#define ARGS_93(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R),O(_S),O(_U),O(_V),O(_W),O(_X),O(_Y)
#define ARGS_94(O) ARGS_71(O),O(_A),O(_B),O(_C),O(_D),O(_E),O(_F),O(_G),O(_H),O(_J),O(_K),O(_L),O(_M),O(_N),O(_P),O(_Q),O(_R),O(_S),O(_U),O(_V),O(_W),O(_X),O(_Y),O(_Z)



#endif // PREPROCESSOR_RE_H_