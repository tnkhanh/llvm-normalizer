/*******************************************************************
 * Author: Ta Quang Trung
 * Date:   July 6th, 2020
 *******************************************************************/

#include "ElimUnusedGlobal.h"

using namespace discover;
using namespace llvm;

char ElimUnusedGlobal::ID = 0;

bool ElimUnusedGlobal::runOnModule(Module &M) {
  StringRef passName = this->getPassName();
  debug() << "=========================================\n"
          << "Running Module Pass: " << passName << "\n";

  GlobalVariableList &globalList = M.getGlobalList();
  SmallSetVector<GlobalVariable*, 16> removableGlobals;

  for (GlobalVariable &global : globalList)
    if (global.getNumUses() == 0)
      removableGlobals.insert(&global);

  for (GlobalVariable *global : removableGlobals) {
    debug() << " - Deleting " << *global << "\n";
    global->removeFromParent();
    // global->deleteValue();
  }

  debug() << "Finish Module Pass: " << passName << "\n";

  return true;
}

static RegisterPass<ElimUnusedGlobal> X("ElimUnusedGlobal",
                                        "ElimUnusedGlobal",
                                        false /* Only looks at CFG */,
                                        true /* Analysis Pass */);

static RegisterStandardPasses Y(PassManagerBuilder::EP_EarlyAsPossible,
                                [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM)
                                {PM.add(new ElimUnusedGlobal());});
