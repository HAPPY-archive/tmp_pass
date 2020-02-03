.PHONY: all,bc,test

MODULE_NAME=libSkeletonPass.so

bc: test.bc

test.bc:    test.c
	clang -O3 -emit-llvm test.c -c -o test.bc

test_bin:	refresh
	 @- clang -Xclang -load -Xclang '/home/happy/llvm_work/MyPass/test/'${MODULE_NAME}  test.c 

test:	refresh
	 @- clang -Xclang -load -Xclang '/home/happy/llvm_work/MyPass/test/'${MODULE_NAME} -emit-llvm -S test.c -o test_modified.ll

gen_bc:
	@ clang -emit-llvm -S test.c -o test.ll

clean:
	- rm ${MODULE_NAME}

refresh:
	@ cp ../cmake-build-debug/src/${MODULE_NAME} ./

# /home/happy/llvm_work/MyPass/test/libSkeletonPass.so
