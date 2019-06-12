##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Coder
ConfigurationName      :=Release
WorkspacePath          :=/home/jacek/CLP/Coder
ProjectPath            :=/home/jacek/CLP/Coder/Coder
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jacek
Date                   :=12/06/19
CodeLitePath           :=/home/jacek/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
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
ObjectsFileList        :="Coder.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++ -std=c++14 -Wall
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -O2 -std=c++14 -Wall $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -O2 -fopenmp -std=c++14 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/EntryInput.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileInput.cpp$(ObjectSuffix) $(IntermediateDirectory)/CodingService.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix): mainwindow.cpp $(IntermediateDirectory)/mainwindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/Coder/mainwindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mainwindow.cpp$(DependSuffix): mainwindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mainwindow.cpp$(DependSuffix) -MM mainwindow.cpp

$(IntermediateDirectory)/mainwindow.cpp$(PreprocessSuffix): mainwindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mainwindow.cpp$(PreprocessSuffix) mainwindow.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/Coder/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/EntryInput.cpp$(ObjectSuffix): EntryInput.cpp $(IntermediateDirectory)/EntryInput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/Coder/EntryInput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EntryInput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EntryInput.cpp$(DependSuffix): EntryInput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EntryInput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EntryInput.cpp$(DependSuffix) -MM EntryInput.cpp

$(IntermediateDirectory)/EntryInput.cpp$(PreprocessSuffix): EntryInput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EntryInput.cpp$(PreprocessSuffix) EntryInput.cpp

$(IntermediateDirectory)/FileInput.cpp$(ObjectSuffix): FileInput.cpp $(IntermediateDirectory)/FileInput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/Coder/FileInput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileInput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileInput.cpp$(DependSuffix): FileInput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileInput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileInput.cpp$(DependSuffix) -MM FileInput.cpp

$(IntermediateDirectory)/FileInput.cpp$(PreprocessSuffix): FileInput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileInput.cpp$(PreprocessSuffix) FileInput.cpp

$(IntermediateDirectory)/CodingService.cpp$(ObjectSuffix): CodingService.cpp $(IntermediateDirectory)/CodingService.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Coder/Coder/CodingService.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CodingService.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CodingService.cpp$(DependSuffix): CodingService.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CodingService.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CodingService.cpp$(DependSuffix) -MM CodingService.cpp

$(IntermediateDirectory)/CodingService.cpp$(PreprocessSuffix): CodingService.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CodingService.cpp$(PreprocessSuffix) CodingService.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


