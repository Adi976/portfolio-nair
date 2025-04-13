import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { FaGithub, FaLinkedin, FaMapMarkerAlt } from 'react-icons/fa';

const FooterContainer = styled.footer`
  background-color: ${({ theme }) => theme.colors.darkBg};
  color: white;
  padding: 60px 0 30px;
  position: relative;
  overflow: hidden;

  @media (max-width: ${({ theme }) => theme.breakpoints.tablet}) {
    padding: 50px 0 25px;
  }

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    padding: 40px 0 20px;
  }

  &::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 1px;
    background: linear-gradient(90deg, transparent, ${({ theme }) => theme.colors.accent}, transparent);
  }
`;

const FooterContent = styled.div`
  max-width: 1200px;
  margin: 0 auto;
  padding: 0 20px;
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 40px;

  @media (max-width: ${({ theme }) => theme.breakpoints.tablet}) {
    flex-direction: column;
    gap: 30px;
    text-align: center;
    padding: 0 15px;
    margin-bottom: 30px;
  }

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    gap: 25px;
    padding: 0 10px;
    margin-bottom: 25px;
  }
`;

const InfoSection = styled.div`
  display: flex;
  flex-direction: column;
  gap: 10px;

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    gap: 8px;
  }
`;

const Location = styled.div`
  display: flex;
  align-items: center;
  gap: 10px;
  color: #999;
  font-size: 0.9rem;

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    font-size: 0.85rem;
    gap: 8px;
  }

  svg {
    color: ${({ theme }) => theme.colors.accent};
  }
`;

const SocialLinks = styled.div`
  display: flex;
  gap: 20px;

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    gap: 15px;
  }
`;

const SocialLink = styled(motion.a)`
  display: inline-flex;
  align-items: center;
  justify-content: center;
  width: 45px;
  height: 45px;
  border-radius: 50%;
  background: rgba(255, 255, 255, 0.1);
  color: white;
  font-size: 1.2rem;
  transition: ${({ theme }) => theme.transition};

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    width: 40px;
    height: 40px;
    font-size: 1.1rem;
  }

  &:hover {
    background: ${({ theme }) => theme.colors.accent};
    transform: translateY(-3px);
  }
`;

const Copyright = styled.div`
  text-align: center;
  color: #666;
  font-size: 0.9rem;
  padding-top: 30px;
  border-top: 1px solid rgba(255, 255, 255, 0.1);

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    font-size: 0.85rem;
    padding-top: 25px;
  }
`;

const ScrollToTop = styled(motion.button)`
  position: fixed;
  bottom: 30px;
  right: 30px;
  width: 50px;
  height: 50px;
  border-radius: 50%;
  background: ${({ theme }) => theme.colors.accent};
  color: white;
  border: none;
  cursor: pointer;
  display: flex;
  align-items: center;
  justify-content: center;
  font-size: 1.2rem;
  box-shadow: 0 5px 15px rgba(0, 0, 0, 0.2);
  transition: ${({ theme }) => theme.transition};
  z-index: 1000;

  @media (max-width: ${({ theme }) => theme.breakpoints.mobile}) {
    width: 45px;
    height: 45px;
    font-size: 1.1rem;
    bottom: 25px;
    right: 25px;
  }

  &:hover {
    transform: translateY(-5px);
    box-shadow: 0 8px 20px rgba(0, 0, 0, 0.3);
  }
`;

const Footer = () => {
  const [showScroll, setShowScroll] = React.useState(false);

  React.useEffect(() => {
    const checkScroll = () => {
      if (window.scrollY > 300) {
        setShowScroll(true);
      } else {
        setShowScroll(false);
      }
    };

    window.addEventListener('scroll', checkScroll);
    return () => window.removeEventListener('scroll', checkScroll);
  }, []);

  const scrollToTop = () => {
    window.scrollTo({
      top: 0,
      behavior: 'smooth'
    });
  };

  const socialLinks = [
    { icon: <FaGithub />, url: 'https://github.com/Adi976', label: 'GitHub' },
    { icon: <FaLinkedin />, url: 'https://www.linkedin.com/in/adithya-nair-in', label: 'LinkedIn' }
  ];

  return (
    <FooterContainer>
      <FooterContent>
        <InfoSection>
          <h3 style={{ marginBottom: '10px', color: 'white' }}>Adithya Nair</h3>
          <p style={{ color: '#999' }}>Full Stack Developer & Machine Learning Enthusiast</p>
          <Location>
            <FaMapMarkerAlt />
            <span>Bangalore, India</span>
          </Location>
        </InfoSection>
        <SocialLinks>
          {socialLinks.map((link, index) => (
            <SocialLink
              key={link.label}
              href={link.url}
              target="_blank"
              rel="noopener noreferrer"
              aria-label={link.label}
              whileHover={{ scale: 1.1 }}
              whileTap={{ scale: 0.9 }}
              initial={{ opacity: 0, y: 20 }}
              animate={{ opacity: 1, y: 0 }}
              transition={{ duration: 0.5, delay: 0.3 + index * 0.1 }}
            >
              {link.icon}
            </SocialLink>
          ))}
        </SocialLinks>
      </FooterContent>
      <Copyright>
        &copy; {new Date().getFullYear()} Adithya Nair. All Rights Reserved.
      </Copyright>
      {showScroll && (
        <ScrollToTop
          onClick={scrollToTop}
          initial={{ opacity: 0, y: 20 }}
          animate={{ opacity: 1, y: 0 }}
          exit={{ opacity: 0, y: 20 }}
          whileHover={{ scale: 1.1 }}
          whileTap={{ scale: 0.9 }}
        >
          ↑
        </ScrollToTop>
      )}
    </FooterContainer>
  );
};

export default Footer; 