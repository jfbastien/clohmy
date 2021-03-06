// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature avx512vbmi -target-feature avx512vl -target-feature avx2 -emit-llvm -o - -Werror | FileCheck %s

// Don't include mm_malloc.h, it's system specific.
#define __MM_MALLOC_H

#include <immintrin.h>


__m128i test_mm_mask2_permutex2var_epi8(__m128i __A, __m128i __I, __mmask16 __U, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask2_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.mask.vpermi2var.qi.128
  return _mm_mask2_permutex2var_epi8(__A, __I, __U, __B); 
}

__m256i test_mm256_mask2_permutex2var_epi8(__m256i __A, __m256i __I, __mmask32 __U, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask2_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.mask.vpermi2var.qi.256
  return _mm256_mask2_permutex2var_epi8(__A, __I, __U, __B); 
}

__m128i test_mm_permutex2var_epi8(__m128i __A, __m128i __I, __m128i __B) {
  // CHECK-LABEL: @test_mm_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.128
  return _mm_permutex2var_epi8(__A, __I, __B); 
}

__m128i test_mm_mask_permutex2var_epi8(__m128i __A, __mmask16 __U, __m128i __I, __m128i __B) {
  // CHECK-LABEL: @test_mm_mask_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.128
  return _mm_mask_permutex2var_epi8(__A, __U, __I, __B); 
}

__m128i test_mm_maskz_permutex2var_epi8(__mmask16 __U, __m128i __A, __m128i __I, __m128i __B) {
  // CHECK-LABEL: @test_mm_maskz_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.maskz.vpermt2var.qi.128
  return _mm_maskz_permutex2var_epi8(__U, __A, __I, __B); 
}

__m256i test_mm256_permutex2var_epi8(__m256i __A, __m256i __I, __m256i __B) {
  // CHECK-LABEL: @test_mm256_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.256
  return _mm256_permutex2var_epi8(__A, __I, __B); 
}

__m256i test_mm256_mask_permutex2var_epi8(__m256i __A, __mmask32 __U, __m256i __I, __m256i __B) {
  // CHECK-LABEL: @test_mm256_mask_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.256
  return _mm256_mask_permutex2var_epi8(__A, __U, __I, __B); 
}

__m256i test_mm256_maskz_permutex2var_epi8(__mmask32 __U, __m256i __A, __m256i __I, __m256i __B) {
  // CHECK-LABEL: @test_mm256_maskz_permutex2var_epi8
  // CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.256
  return _mm256_maskz_permutex2var_epi8(__U, __A, __I, __B); 
}