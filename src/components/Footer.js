import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { FaGithub, FaLinkedin, FaTwitter, FaInstagram } from 'react-icons/fa';

const FooterContainer = styled.footer`
  background-color: ${props => props.theme.colors.darkBg};
  color: ${props => props.theme.colors.white};
  padding: ${props => props.theme.spacing.xl} 0 ${props => props.theme.spacing.lg};
`;

const SocialLinks = styled.div`
  display: flex;
  justify-content: center;
  gap: ${props => props.theme.spacing.lg};
  margin-bottom: ${props => props.theme.spacing.xl};
`;

const SocialLink = styled(motion.a)`
  color: ${props => props.theme.colors.white};
  font-size: 1.5rem;
  transition: ${props => props.theme.transitions.default};

  &:hover {
    color: ${props => props.theme.colors.accent};
    transform: translateY(-3px);
  }
`;

const Copyright = styled.div`
  text-align: center;
  color: #999;
  font-size: 0.9rem;
`;

const Footer = () => {
  const socialLinks = [
    { icon: <FaGithub />, url: 'https://github.com/yourusername' },
    { icon: <FaLinkedin />, url: 'https://linkedin.com/in/yourusername' },
    { icon: <FaTwitter />, url: 'https://twitter.com/yourusername' },
    { icon: <FaInstagram />, url: 'https://instagram.com/yourusername' },
  ];

  return (
    <FooterContainer>
      <div className="container">
        <SocialLinks>
          {socialLinks.map((link, index) => (
            <SocialLink
              key={index}
              href={link.url}
              target="_blank"
              rel="noopener noreferrer"
              whileHover={{ scale: 1.1 }}
              whileTap={{ scale: 0.9 }}
            >
              {link.icon}
            </SocialLink>
          ))}
        </SocialLinks>
        <Copyright>
          &copy; {new Date().getFullYear()} Adithya Nair. All Rights Reserved.
        </Copyright>
      </div>
    </FooterContainer>
  );
};

export default Footer; 