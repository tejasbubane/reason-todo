const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

const outputDir = path.join(__dirname, "dist/");
const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: './lib/js/src/Index.bs.js',
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'bundle.js',
  },
  devServer: {
    contentBase: outputDir,
    compress: true,
    port: 8000
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: path.join(__dirname, "templates/index.html")
    })
  ]
};
