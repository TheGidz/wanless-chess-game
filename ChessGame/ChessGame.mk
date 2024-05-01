##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ChessGame
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame
ProjectPath            :=C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Gideon
Date                   :=4/30/2024
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe
SharedObjectLinkerName :=C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe -shared -fPIC
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
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ChessGame.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/cygwin64/bin/x86_64-pc-cygwin-ar.exe rcu
CXX      := C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe
CC       := C:/cygwin64/bin/x86_64-pc-cygwin-gcc.exe
CXXFLAGS :=  -std=c++11 -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/x86_64-pc-cygwin-as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/bishop.cpp$(ObjectSuffix) $(IntermediateDirectory)/queen.cpp$(ObjectSuffix) $(IntermediateDirectory)/game_board.cpp$(ObjectSuffix) $(IntermediateDirectory)/rook.cpp$(ObjectSuffix) $(IntermediateDirectory)/king.cpp$(ObjectSuffix) $(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) $(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IntermediateDirectory)/knight.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/game_piece.cpp$(ObjectSuffix) \
	



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
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/bishop.cpp$(ObjectSuffix): bishop.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bishop.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bishop.cpp$(DependSuffix) -MM bishop.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/bishop.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bishop.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bishop.cpp$(PreprocessSuffix): bishop.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bishop.cpp$(PreprocessSuffix) bishop.cpp

$(IntermediateDirectory)/queen.cpp$(ObjectSuffix): queen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/queen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/queen.cpp$(DependSuffix) -MM queen.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/queen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/queen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/queen.cpp$(PreprocessSuffix): queen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/queen.cpp$(PreprocessSuffix) queen.cpp

$(IntermediateDirectory)/game_board.cpp$(ObjectSuffix): game_board.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game_board.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game_board.cpp$(DependSuffix) -MM game_board.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/game_board.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game_board.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game_board.cpp$(PreprocessSuffix): game_board.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game_board.cpp$(PreprocessSuffix) game_board.cpp

$(IntermediateDirectory)/rook.cpp$(ObjectSuffix): rook.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rook.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/rook.cpp$(DependSuffix) -MM rook.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/rook.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rook.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rook.cpp$(PreprocessSuffix): rook.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rook.cpp$(PreprocessSuffix) rook.cpp

$(IntermediateDirectory)/king.cpp$(ObjectSuffix): king.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/king.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/king.cpp$(DependSuffix) -MM king.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/king.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/king.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/king.cpp$(PreprocessSuffix): king.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/king.cpp$(PreprocessSuffix) king.cpp

$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix): pawn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pawn.cpp$(DependSuffix) -MM pawn.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/pawn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix): pawn.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix) pawn.cpp

$(IntermediateDirectory)/game.cpp$(ObjectSuffix): game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game.cpp$(DependSuffix) -MM game.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game.cpp$(PreprocessSuffix): game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game.cpp$(PreprocessSuffix) game.cpp

$(IntermediateDirectory)/knight.cpp$(ObjectSuffix): knight.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/knight.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/knight.cpp$(DependSuffix) -MM knight.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/knight.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/knight.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/knight.cpp$(PreprocessSuffix): knight.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/knight.cpp$(PreprocessSuffix) knight.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/game_piece.cpp$(ObjectSuffix): game_piece.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game_piece.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game_piece.cpp$(DependSuffix) -MM game_piece.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gideon/Documents/ariClassStuff/CLearning/chessGame/ChessGame/game_piece.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game_piece.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game_piece.cpp$(PreprocessSuffix): game_piece.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game_piece.cpp$(PreprocessSuffix) game_piece.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


