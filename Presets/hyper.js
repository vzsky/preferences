// Future versions of Hyper may add additional config options,
// which will not automatically be merged into this file.
// See https://hyper.is#cfg for all currently supported options.


module.exports = {
  config: {

    updateChannel: 'stable',
    fontSize: 15,
    fontFamily: '"Fira Code", Menlo, "DejaVu Sans Mono", Consolas, "Lucida Console", monospace',
    // default font weight: 'normal' or 'bold'
    fontWeight: 'normal', 
    webGLRenderer: false,
    bell:false,
    backgroundColor: "rgba(50, 50, 50, 0.8)",
    cursorColor: "#3dd", 
    selectionColor: "rgba(200, 200, 200, 0.3)",

  },
  plugins: [
    "hyper-font-ligatures",
    "hypercwd",
    "hyper-alt-click",
    "hyperterm-safepaste",
  ],
};