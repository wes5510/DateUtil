include ./config.mak

all: exec tests

exec:
	$(ECHO) $(SRC_DIR); $(MAKE) -C $(SRC_DIR)

tests: exec
	$(ECHO) $(TESTS_DIR); $(MAKE) -C $(TESTS_DIR)

clean:
	$(MAKE_CLEAN) -C $(SRC_DIR)
	$(MAKE_CLEAN) -C $(TESTS_DIR)
