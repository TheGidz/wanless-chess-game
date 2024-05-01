.PHONY: clean All

All:
	@echo "----------Building project:[ ChessGame - Debug ]----------"
	@cd "ChessGame" && "$(MAKE)" -f  "ChessGame.mk"
clean:
	@echo "----------Cleaning project:[ ChessGame - Debug ]----------"
	@cd "ChessGame" && "$(MAKE)" -f  "ChessGame.mk" clean
