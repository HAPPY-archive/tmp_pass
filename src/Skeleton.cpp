#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

// typical c++ header
#include <random>
#include <ctime>

using namespace llvm;


//    struct SkeletonPass : public FunctionPass {
//        static char ID;
//
//        SkeletonPass() : FunctionPass(ID) {}
//
//        bool runOnFunction(Function &F) override {
//            llvm::outs() << "I saw a function called " << F.getName() << "!\n";
//            return false;
//        }
//    };
namespace {
    struct ConstantEncryption : public ModulePass {
        static char ID;
        std::random_device rd;
        std::default_random_engine randomEngine{rd()};

        ConstantEncryption() : ModulePass(ID) {}

        bool runOnModule(Module &M) override {

            llvm::outs() << "Running in the module !\n";

            for (auto &F : M) {
                outs() << "I Find " + F.getName() << "\n";
            }

            return true;
        }
    };

}

//char SkeletonPass::ID = 1;
char ConstantEncryption::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.htmlgoowo
static void registerSkeletonPass(const PassManagerBuilder &,
                                 legacy::PassManagerBase &PM) {
    PM.add(new ConstantEncryption());
//    PM.add(new SkeletonPass());
}

static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerSkeletonPass);
//static RegisterPass<SkeletonPass> X("-skeleton", "Constant Encryption");

//static RegisterPass<SkeletonPass> X("skeleton", "This is Skeleton Pass powered by HAPPY”);
