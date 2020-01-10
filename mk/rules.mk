$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

test_runner:
	cxxtestgen --error-printer -o $@.cpp $(TESTS)
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp -Icxxtest

test: test_runner
	-./test_runner
	$(RM) test_runner test_runner.cpp

testKeep: test_runner
	./test_runner

clean:
	$(RM) -r $(BUILD_DIR) test_runner*
