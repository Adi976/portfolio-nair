import React from 'react';
import { ThemeProvider } from 'styled-components';
import { theme } from './theme';
import GlobalStyles from './styles/GlobalStyles';
import Header from './components/Header';
import Hero from './components/Hero';
import About from './components/About';
import Projects from './components/Projects';
import Resume from './components/Resume';
import Gallery from './components/Gallery';
import Contact from './components/Contact';
import Footer from './components/Footer';

function App() {
  return (
    <ThemeProvider theme={theme}>
      <GlobalStyles />
      <Header />
      <main>
        <Hero />
        <About />
        <Projects />
        <Resume />
        <Gallery />
        <Contact />
      </main>
      <Footer />
    </ThemeProvider>
  );
}

export default App;
