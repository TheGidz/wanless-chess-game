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
MakeDirCommand         :=mkdir -p
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
AR       := C:/cygwin64/bin/ar.exe rcu
CXX      := C:/cygwin64/bin/g++.exe
CC       := C:/cygwin64/bin/gcc.exe
CXXFLAGS :=  -std=c++11 -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/cygwin64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/queen.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bishop.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameBoard.cpp$(ObjectSuffix) $(IntermediateDirectory)/Rook.cpp$(ObjectSuffix) $(IntermediateDirectory)/king.cpp$(ObjectSuffix) $(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) $(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IntermediateDirectory)/knight.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/GamePiece.cpp$(ObjectSuffix) \
	



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
$(IntermediateDirectory)/queen.cpp$(ObjectSuffix): pieces/src/queen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/queen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/queen.cpp$(DependSuffix) -MM pieces/src/Queen.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/pieces/src/Queen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/queen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/queen.cpp$(PreprocessSuffix): queen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/queen.cpp$(PreprocessSuffix) queen.cpp

$(IntermediateDirectory)/Bishop.cpp$(ObjectSuffix): pieces/src/Bishop.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)Bishop.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bishop.cpp$(DependSuffix) -MM pieces/src/Bishop.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/pieces/src/Bishop.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bishop.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bishop.cpp$(PreprocessSuffix): Bishop.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bishop.cpp$(PreprocessSuffix) Bishop.cpp

$(IntermediateDirectory)/GameBoard.cpp$(ObjectSuffix): src/GameBoard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameBoard.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameBoard.cpp$(DependSuffix) -MM src/GameBoard.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/src/GameBoard.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameBoard.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameBoard.cpp$(PreprocessSuffix): GameBoard.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameBoard.cpp$(PreprocessSuffix) GameBoard.cpp

$(IntermediateDirectory)/Rook.cpp$(ObjectSuffix): pieces/src/Rook.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Rook.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Rook.cpp$(DependSuffix) -MM pieces/src/Rook.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/pieces/src/Rook.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Rook.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Rook.cpp$(PreprocessSuffix): Rook.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Rook.cpp$(PreprocessSuffix) Rook.cpp

$(IntermediateDirectory)/king.cpp$(ObjectSuffix): pieces/src/king.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/king.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/king.cpp$(DependSuffix) -MM pieces/src/King.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/pieces/src/king.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/king.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/king.cpp$(PreprocessSuffix): king.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/king.cpp$(PreprocessSuffix) king.cpp

$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix): pieces/src/pawn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pawn.cpp$(DependSuffix) -MM pieces/src/Pawn.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/pieces/src/pawn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pawn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix): pawn.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pawn.cpp$(PreprocessSuffix) pawn.cpp

$(IntermediateDirectory)/game.cpp$(ObjectSuffix): src/game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game.cpp$(DependSuffix) -MM src/Game.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/src/game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game.cpp$(PreprocessSuffix): game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game.cpp$(PreprocessSuffix) game.cpp

$(IntermediateDirectory)/knight.cpp$(ObjectSuffix): pieces/src/knight.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/knight.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/knight.cpp$(DependSuffix) -MM pieces/src/Knight.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/pieces/src/knight.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/knight.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/knight.cpp$(PreprocessSuffix): knight.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/knight.cpp$(PreprocessSuffix) knight.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM src/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/GamePiece.cpp$(ObjectSuffix): pieces/src/GamePiece.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GamePiece.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GamePiece.cpp$(DependSuffix) -MM pieces/src/GamePiece.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin64/home/Gideon/wanlessPersonalProjects/wanless-chess-game/ChessGame/pieces/src/GamePiece.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GamePiece.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GamePiece.cpp$(PreprocessSuffix): GamePiece.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GamePiece.cpp$(PreprocessSuffix) GamePiece.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


