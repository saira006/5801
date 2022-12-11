#include "group.h"

Group::Group() {
  startLine = -1;
  endLine = -1;
  comment = "";
}

Group::Group(int start, int end) {
  startLine = start;
  endLine = end;
  comment = "";
}

void Group::setStart(int lineNum) { startLine = lineNum; }

int Group::getStart() { return startLine; }

void Group::setEnd(int lineNum) { endLine = lineNum; }

int Group::getEnd() { return endLine; }