$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

test_runner:
	cxxtestgen --error-printer -o $@.cpp $(TESTS)
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp -I$(CXXTEST)

test: test_runner
	./test_runner
	rm test_runner test_runner.cpp

clean:
	rm -rf $(BUILD_DIR) test_runner*
