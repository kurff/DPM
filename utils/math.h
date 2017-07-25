#ifndef _KURFF_UTILS_MATH_H_
#define _KURFF_UTILS_MATH_H_
// This is a simple translation from the old Caffe math interfaces. We aim to
// still keep it simple, so all platforms would be able to support it fairly
// easily.

extern "C" {
#include "cblas.h"
}

#include "tensor/common.hpp"


namespace kurff {

namespace math {

template <typename T, class Context>
void Exp(const int N, const T* x, T* y, Context* context);
template <typename T, class Context>
void Log(const int N, const T* x, T* y, Context* context);
template <typename T, class Context>
void Sqr(const int N, const T* x, T* y, Context* context);

template <typename T, class Context>
void Powx(const int N, const T* a, const T b, T* y, Context* context);


template <typename T, class Context>
void Add(const int N, const T* a, const T* b, T* y, Context* context);
template <typename T, class Context>
void Sub(const int N, const T* a, const T* b, T* y, Context* context);
template <typename T, class Context>
void Mul(const int N, const T* a, const T* b, T* y, Context* context);
template <typename T, class Context>
void Div(const int N, const T* a, const T* b, T* y, Context* context);


// Compute the row-wise max of a N*D matrix X, and write it to a N
// dimensional vector y.
template <typename T, class Context>
void RowwiseMax(const int N, const int D, const T* x, T* y,
                Context* context);

// Compute the column-wise max of a N*D matrix X, and write it to a D
// dimensional vector y.
template <typename T, class Context>
void ColwiseMax(const int N, const int D, const T* x, T* y,
                Context* context);

// AddToRow and AddToCol adds the corresponding row/col vector x to the matrix y
// of shape MxN.
template <typename T, class Context>
void AddToRow(const int M, const int N, const T* x, T* y,
              Context* context);
template <typename T, class Context>
void AddToCol(const int M, const int N, const T* x, T* y,
              Context* context);

// Decaf gemm provides a simpler interface to the gemm functions, with the
// limitation that the data has to be contiguous in memory.
template <typename T, class Context>
void Gemm(const CBLAS_TRANSPOSE TransA, const CBLAS_TRANSPOSE TransB,
    const int M, const int N, const int K, const T alpha, const T* A,
    const T* B, const T beta, T* C, Context* context);

// Gemv always takes in a M*N matrix A, and depending on whether we set TransA
// to Trans, the output is:
// CblasNoTrans: x is an N dim vector and y is an M dim vector.
// CblasTrans:   x is an M dim vector and y is an N dim vector.
template <typename T, class Context>
void Gemv(const CBLAS_TRANSPOSE TransA, const int M, const int N,
    const T alpha, const T* A, const T* x, const T beta,
    T* y, Context* context);

template <typename T, class Context>
void Set(const int N, const T alpha, T* X, Context* context);

template <typename T, class Context>
void RandUniform(const int n, const T a, const T b, T* r,
                 Context* context);

template <typename T, class Context>
void RandGaussian(const int n, const T mean, const T std, T* r,
                  Context* context);

// Dot matrix of vector a and b, and writes the result to a single value y.
template <typename T, class Context>
void Dot(const int N, const T* a, const T* b, T* y, Context* context);

// Sum of vector x, and writes the result to a single value y.
template <typename T, class Context>
void Sum(const int N, const T* x, T* y, Context* context);

// Select does index selection of the rows a N*D matrix x, and gives the N
// dimensional vector y that contains the selected data.
template <typename T, class Context>
void Select(const int N, const int D, const T* x, const int* idx, T* y,
            Context* context);

template <typename T, class Context>
void Scale(const int N, const T alpha, const T* x, T* y,
           Context* context);

// Different from the Scale function above, if alpha is passed in
// as a pointer, we will assume that it lives on the Context device,
// for example on GPU.
template <typename T, class Context>
void Scale(const int N, const T* alpha, const T* x, T* y,
           Context* context);

template <typename T, class Context>
void Axpy(const int N, const T alpha, const T* x, T* y,
          Context* context);

// Different from the Axpy function above, if alpha is passed in
// as a pointer, we will assume that it lives on the Context device,
// for example on GPU.
template <typename T, class Context>
void Axpy(const int N, const T* alpha, const T* x, T* y,
          Context* context);

template <typename T, class Context>
void Axpby(const int N, const T alpha, const T* x, const T b, T* y,
           Context* context);

template <typename T, class Context, int order>
void Im2col(const T* data_im, const int channels,
    const int height, const int width, const int kernel_h, const int kernel_w,
    const int pad_t, const int pad_l, const int pad_b, const int pad_r,
    const int stride_h, const int stride_w, T* data_col,
    Context* context);

template <typename T, class Context, int order>
void Col2im(const T* data_col, const int channels,
    const int height, const int width, const int patch_h, const int patch_w,
    const int pad_t, const int pad_l, const int pad_b, const int pad_r,
    const int stride_h, const int stride_w, T* data_im,
    Context* context);

template <class Context>
void CopyMatrix(const size_t item_size, const int M, const int N, const void* A,
                const int lda, void* B, const int ldb, Context* context);

}  // namespace math
}  // namespace kurff


#endif  // _KURFF_UTILS_MATH_H_
