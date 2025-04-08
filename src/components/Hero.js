import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { FaArrowRight } from 'react-icons/fa';

const HeroSection = styled.section`
  min-height: 100vh;
  display: flex;
  align-items: center;
  padding: 120px 0 80px;
  background: linear-gradient(135deg, ${props => props.theme.colors.lightBg} 0%, ${props => props.theme.colors.white} 100%);
  position: relative;
  overflow: hidden;

  &::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: radial-gradient(circle at 50% 50%, rgba(0, 113, 227, 0.1) 0%, transparent 70%);
    pointer-events: none;
  }
`;

const HeroContent = styled(motion.div)`
  max-width: 600px;
`;

const Title = styled(motion.h1)`
  font-size: 4rem;
  font-weight: 700;
  line-height: 1.1;
  margin-bottom: 24px;
  background: linear-gradient(45deg, ${props => props.theme.colors.primary}, ${props => props.theme.colors.accent});
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;

  @media (max-width: ${props => props.theme.breakpoints.desktop}) {
    font-size: 3rem;
  }

  @media (max-width: ${props => props.theme.breakpoints.mobile}) {
    font-size: 2.5rem;
  }
`;

const Description = styled(motion.p)`
  font-size: 1.25rem;
  color: #666;
  margin-bottom: 40px;
  line-height: 1.6;
`;

const CTAButton = styled(motion.a)`
  display: inline-flex;
  align-items: center;
  gap: 10px;
  background-color: ${props => props.theme.colors.accent};
  color: ${props => props.theme.colors.white};
  padding: 16px 32px;
  border-radius: 30px;
  font-weight: 500;
  transition: ${props => props.theme.transitions.default};

  &:hover {
    transform: translateY(-2px);
    box-shadow: 0 10px 20px rgba(0, 113, 227, 0.2);
  }
`;

const Hero = () => {
  const containerVariants = {
    hidden: { opacity: 0 },
    visible: {
      opacity: 1,
      transition: {
        staggerChildren: 0.2,
      },
    },
  };

  const itemVariants = {
    hidden: { opacity: 0, y: 20 },
    visible: {
      opacity: 1,
      y: 0,
      transition: {
        duration: 0.5,
      },
    },
  };

  return (
    <HeroSection id="home">
      <div className="container">
        <HeroContent
          variants={containerVariants}
          initial="hidden"
          animate="visible"
        >
          <Title variants={itemVariants}>
            Hi, I'm Adithya Nair
          </Title>
          <Description variants={itemVariants}>
            I'm a passionate student specializing in Machine Learning, dedicated to creating innovative solutions that make everyday tasks more efficient and enjoyable.
          </Description>
          <CTAButton
            href="#contact"
            variants={itemVariants}
            whileHover={{ scale: 1.05 }}
            whileTap={{ scale: 0.95 }}
          >
            Get In Touch
            <FaArrowRight />
          </CTAButton>
        </HeroContent>
      </div>
    </HeroSection>
  );
};

export default Hero; 