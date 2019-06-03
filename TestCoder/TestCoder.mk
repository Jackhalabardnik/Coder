##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=TestCoder
ConfigurationName      :=Release
WorkspacePath          :=/home/jacek/CLP/Coder
ProjectPath            :=/home/jacek/CLP/Coder/TestCoder
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jacek
Date                   :=03/06/19
CodeLitePath           :=/home/jacek/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TestCoder.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/home/jacek/CLP/Coder $(IncludeSwitch)/home/jacek/CLP $(IncludeSwitch)/home/jacek/CLP/Coder/Coder 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -std=c++14 -std=c++11 -Wall $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/mainwindowtests.cpp$(ObjectSuffix) $(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix) $(IntermediateDirectory)/entryinputtests.cpp$(ObjectSuffix) $(IntermediateDirectory)/fileinputtests.cpp$(ObjectSuffix) $(IntermediateDirectory)/MockWindow.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/mainwindowtests.cpp$(ObjectSuffix): mainwindowtests.cpp $(IntermediateDirectory)/mainwindowtests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/TestCoder/mainwindowtests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mainwindowtests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mainwindowtests.cpp$(DependSuffix): mainwindowtests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mainwindowtests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mainwindowtests.cpp$(DependSuffix) -MM mainwindowtests.cpp

$(IntermediateDirectory)/mainwindowtests.cpp$(PreprocessSuffix): mainwindowtests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mainwindowtests.cpp$(PreprocessSuffix) mainwindowtests.cpp

$(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix): CatchMain.cpp $(IntermediateDirectory)/CatchMain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/TestCoder/CatchMain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CatchMain.cpp$(DependSuffix): CatchMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CatchMain.cpp$(DependSuffix) -MM CatchMain.cpp

$(IntermediateDirectory)/CatchMain.cpp$(PreprocessSuffix): CatchMain.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CatchMain.cpp$(PreprocessSuffix) CatchMain.cpp

$(IntermediateDirectory)/entryinputtests.cpp$(ObjectSuffix): entryinputtests.cpp $(IntermediateDirectory)/entryinputtests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/TestCoder/entryinputtests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entryinputtests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entryinputtests.cpp$(DependSuffix): entryinputtests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entryinputtests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entryinputtests.cpp$(DependSuffix) -MM entryinputtests.cpp

$(IntermediateDirectory)/entryinputtests.cpp$(PreprocessSuffix): entryinputtests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entryinputtests.cpp$(PreprocessSuffix) entryinputtests.cpp

$(IntermediateDirectory)/fileinputtests.cpp$(ObjectSuffix): fileinputtests.cpp $(IntermediateDirectory)/fileinputtests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/TestCoder/fileinputtests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fileinputtests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fileinputtests.cpp$(DependSuffix): fileinputtests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fileinputtests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/fileinputtests.cpp$(DependSuffix) -MM fileinputtests.cpp

$(IntermediateDirectory)/fileinputtests.cpp$(PreprocessSuffix): fileinputtests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fileinputtests.cpp$(PreprocessSuffix) fileinputtests.cpp

$(IntermediateDirectory)/MockWindow.cpp$(ObjectSuffix): MockWindow.cpp $(IntermediateDirectory)/MockWindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/TestCoder/MockWindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MockWindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MockWindow.cpp$(DependSuffix): MockWindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MockWindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MockWindow.cpp$(DependSuffix) -MM MockWindow.cpp

$(IntermediateDirectory)/MockWindow.cpp$(PreprocessSuffix): MockWindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MockWindow.cpp$(PreprocessSuffix) MockWindow.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


