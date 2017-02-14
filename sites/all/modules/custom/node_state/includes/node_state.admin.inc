<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 *
 */
function node_state_config_form($form, &$form_state) {
  $form = array();
  
  $form['label'] = array(
    '#markup' => t('Hello!'),
  );

  return $form;
}

/**
 * Form admin configuration.
 *
 */
function node_state_node_config_form($form, &$form_state) {
  $form = array();
  
  $form['label'] = array(
    '#markup' => t('Hello2!'),
  );

  return $form;
}