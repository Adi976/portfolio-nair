import { createGlobalStyle } from 'styled-components';

const GlobalStyles = createGlobalStyle`
  * {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
  }

  html {
    scroll-behavior: smooth;
  }

  body {
    font-family: ${props => props.theme.fonts.body};
    line-height: 1.6;
    color: ${props => props.theme.colors.text};
    background-color: ${props => props.theme.colors.lightBg};
    overflow-x: hidden;
  }

  a {
    text-decoration: none;
    color: inherit;
  }

  button {
    cursor: pointer;
    border: none;
    background: none;
    font-family: inherit;
  }

  img {
    max-width: 100%;
    height: auto;
  }

  .container {
    max-width: 1200px;
    margin: 0 auto;
    padding: 0 ${props => props.theme.spacing.md};
  }

  section {
    padding: ${props => props.theme.spacing.xl} 0;
  }

  .animate {
    opacity: 0;
    transform: translateY(20px);
    transition: ${props => props.theme.transitions.default};
  }

  .animate.visible {
    opacity: 1;
    transform: translateY(0);
  }
`;

export default GlobalStyles; 