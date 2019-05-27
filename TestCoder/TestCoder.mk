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
Date                   :=27/05/19
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/home/jacek/CLP/Coder $(IncludeSwitch)/home/jacek/CLP/CoderRepo/ 
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
Objects0=$(IntermediateDirectory)/mainwindowtests.cpp$(ObjectSuffix) $(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix) 



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


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


