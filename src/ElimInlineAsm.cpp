#include "ElimInlineAsm.h"

using namespace discover;
using namespace llvm;

char ElimInlineAsm::ID = 0;

bool ElimInlineAsm::runOnModule(Module &M) {
  StringRef passName = this->getPassName();
  debug() << "=========================================\n"
          << "Running Module Pass: " << passName << "\n";

  M.setModuleInlineAsm("");

  debug() << "Finish Module Pass: " << passName << "\n";

  return true;
}

static RegisterPass<ElimInlineAsm> X("ElimInlineAsm",
                                        "ElimInlineAsm",
                                        false /* Only looks at CFG */,
                                        true /* Analysis Pass */);

static RegisterStandardPasses Y(PassManagerBuilder::EP_EarlyAsPossible,
                                [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM)
                                {PM.add(new ElimInlineAsm());});
