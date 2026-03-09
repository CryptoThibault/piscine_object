#!/bin/sh

if [ $# -ne 1 ]; then
    echo "Usage: $0 ClassName"
    exit 1
fi

CLASS=$1
UPPER=$(echo "$CLASS" | tr '[:lower:]' '[:upper:]')

HPP="${CLASS}.hpp"
CPP="${CLASS}.cpp"

cat << EOF > $HPP
#ifndef ${UPPER}_HPP
#define ${UPPER}_HPP

class ${CLASS} {
public:
    ${CLASS}();
    ${CLASS}(const ${CLASS}& other);
    ${CLASS}& operator=(const ${CLASS}& other);
    ~${CLASS}();
};

#endif
EOF

cat << EOF > $CPP
#include "${CLASS}.hpp"

${CLASS}::${CLASS}() {}

${CLASS}::${CLASS}(const ${CLASS}& other) {}

${CLASS}& ${CLASS}::operator=(const ${CLASS}& other) {
    if (this != &other) {}
    return *this;
}

${CLASS}::~${CLASS}() {}
EOF

echo "Created ${HPP} and ${CPP}"
