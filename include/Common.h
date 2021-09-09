#ifndef COMMON_H
#define COMMON_H

#include <iostream>

#include "llvm/IR/Type.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/ADT/SetVector.h"


using namespace std;
using namespace llvm;

namespace llvm {

using GlobalVariableList = SymbolTableList<GlobalVariable>;
using FunctionList = SymbolTableList<Function>;
using BasicBlockList = SymbolTableList<BasicBlock>;
using FunctionSet = SmallSetVector<Function*, 16>;

const std::string LLVM_GLOBAL_CTORS = "llvm.global_ctors";

bool isDiscoverTestingFunc(Function&);
void replaceOperand(Function *func, Value *oldOpr, Value *newOpr);
void replacePhiSource(Function *func, BasicBlock *oldOpr, BasicBlock *newOpr);

}

#endif
