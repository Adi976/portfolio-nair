import React, { useState, useEffect } from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { FaBars, FaTimes } from 'react-icons/fa';

const HeaderContainer = styled.header`
  background-color: rgba(255, 255, 255, 0.8);
  backdrop-filter: blur(10px);
  -webkit-backdrop-filter: blur(10px);
  position: fixed;
  width: 100%;
  top: 0;
  z-index: 1000;
  transition: ${props => props.theme.transitions.default};
  box-shadow: ${props => props.scrolled ? props.theme.shadows.small : 'none'};
`;

const Nav = styled.nav`
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: ${props => props.theme.spacing.md} 0;
`;

const Logo = styled.div`
  font-size: 1.5rem;
  font-weight: 600;
  color: ${props => props.theme.colors.primary};
  letter-spacing: -0.5px;
`;

const NavLinks = styled.ul`
  display: flex;
  list-style: none;
  gap: ${props => props.theme.spacing.lg};

  @media (max-width: ${props => props.theme.breakpoints.tablet}) {
    display: ${props => props.isOpen ? 'flex' : 'none'};
    flex-direction: column;
    position: fixed;
    top: 0;
    right: 0;
    width: 100%;
    height: 100vh;
    background-color: ${props => props.theme.colors.white};
    padding: ${props => props.theme.spacing.xl};
    align-items: center;
    justify-content: center;
  }
`;

const NavLink = styled(motion.li)`
  a {
    color: ${props => props.theme.colors.text};
    font-weight: 500;
    font-size: 0.95rem;
    position: relative;
    padding: 5px 0;

    &::after {
      content: '';
      position: absolute;
      bottom: 0;
      left: 0;
      width: 0;
      height: 2px;
      background-color: ${props => props.theme.colors.accent};
      transition: ${props => props.theme.transitions.default};
    }

    &:hover::after {
      width: 100%;
    }
  }
`;

const MobileMenuButton = styled.button`
  display: none;
  font-size: 1.5rem;
  color: ${props => props.theme.colors.primary};
  background: none;
  border: none;
  cursor: pointer;

  @media (max-width: ${props => props.theme.breakpoints.tablet}) {
    display: block;
    z-index: 1001;
  }
`;

const Header = () => {
  const [scrolled, setScrolled] = useState(false);
  const [isOpen, setIsOpen] = useState(false);

  useEffect(() => {
    const handleScroll = () => {
      setScrolled(window.scrollY > 50);
    };

    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  const navLinks = [
    { name: 'Home', href: '#home' },
    { name: 'About', href: '#about' },
    { name: 'Projects', href: '#projects' },
    { name: 'Contact', href: '#contact' },
  ];

  return (
    <HeaderContainer scrolled={scrolled}>
      <div className="container">
        <Nav>
          <Logo>Adithya Nair</Logo>
          <MobileMenuButton onClick={() => setIsOpen(!isOpen)}>
            {isOpen ? <FaTimes /> : <FaBars />}
          </MobileMenuButton>
          <NavLinks isOpen={isOpen}>
            {navLinks.map((link, index) => (
              <NavLink
                key={link.name}
                initial={{ opacity: 0, y: -20 }}
                animate={{ opacity: 1, y: 0 }}
                transition={{ delay: index * 0.1 }}
              >
                <a href={link.href} onClick={() => setIsOpen(false)}>
                  {link.name}
                </a>
              </NavLink>
            ))}
          </NavLinks>
        </Nav>
      </div>
    </HeaderContainer>
  );
};

export default Header; 