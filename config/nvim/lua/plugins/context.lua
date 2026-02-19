vim.g.context_max_per_indent = 3
vim.g.context_skip_regex = '^\\s*\\($\\|#\\|//\\|/\\*\\|\\*($\\|\\s*$\\)'
vim.g.context_extend_regex =
  '^\\s*\\([\\[\\]{}()]\\|end\\|else\\|\\(case\\|default\\|done\\|elif\\|fi\\)\\>\\|public:\\|private:\\|protected:\\)'

return {
  'wellle/context.vim',
  config = function ()
    -- set here doesn't work
  end
}
