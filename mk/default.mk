BUILD_DIR = build
COMMON = $(ROOT)/common

.DEFAULT_GOAL = $(BUILD_DIR)/$(TARGET)
.SECONDARY: $(OBJS)

SRCS += $(wildcard *.cpp)
OBJS += $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS += $(OBJS:.o=.d)
-include $(DEPS)
