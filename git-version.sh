#!/bin/sh

# see doxy.conf FILE_VERSION_FILTER

[[ -e .git ]] || (echo "unknown" && exit 0)

GIT_VERSION=$(git log --pretty=format:%H -n 1 2> /dev/null)
if test -z ${GIT_VERSION}; then
	VERSION='unknown'
else
	VERSION=${GIT_VERSION}
fi

echo ${VERSION}
