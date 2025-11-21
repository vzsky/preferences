#!/bin/bash

# if ignore_debug is set and a DEBUG_PATTERN is found in diff of any file, 
ignore_debug=false
DEBUG_PATTERN="penguin" # distinct word i use for debugging

while [[ "$#" -gt 0 ]]; do
  case "$1" in
    -ignore_debug)
      ignore_debug=true
      shift
      ;;
    -help)
      echo "
      Usage:
        format_added  
      { OPTIONAL:
        [-ignore_debug: Ignore the warning for your pattern, \"$DEBUG_PATTERN\"]
      }"
      exit 1
      shift
      ;;
    *)
      echo "Unknown option: $1"
      shift
      ;;
  esac
done

###############################################################################
# MAIN LOOP — STAGED FILES ONLY
###############################################################################
git status --porcelain -z | while IFS= read -r -d '' entry; do
  # entry looks like: "XY filename\0"
  X=${entry:0:1}

  [[ "$X" == " " ]] && continue

  # Extract filename (after "XY ")
  file="${entry:3}"
  base="$(basename "$file")"

  ###########################################################################
  # Handle DELETED files immediately (no formatting needed)
  ###########################################################################
  if [[ "$X" == "D" ]]; then
    echo "Deleted $file"
    git add "$file"
    continue
  fi

  ###########################################################################
  # Debug pattern check
  ###########################################################################
  if matches=$(rg -n "$PATTERN" "$file"); then
    echo "!! \'$PATTERN\' found in $file, examine this"
    echo "$matches"
    if [ "$ignore_debug" = false ]; then
      exit 1
    fi
  fi

  ###########################################################################
  # Formatting logic
  ###########################################################################
  if [[ "$base" == *".cc" || "$base" == *".h" ]]; then 
    echo "Formatting $file using clang-format"
    clang-format -i "$file"

  elif [[ "$base" == *"CMakeLists.txt" ]]; then
    echo "Formatting $file using cmake-format"
    cmake-format -i "$file"

  else
    echo "Not Formatting $file"
    clang-format -i "$file"
  fi

  git add "$file"
done

git fetch; 
