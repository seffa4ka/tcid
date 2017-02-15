<?php

/**
 * @file
 * Form.
 */

/**
 * Form admin configuration.
 *
 */
function node_log_config_form($form, &$form_state) {
  $form = array();

  return $form;
}

/**
 * Form admin configuration.
 *
 */
function node_log_node_config_form($form, &$form_state) {
  $form = array();
  
  $form['label'] = array(
    '#markup' => t('Hello2!'),
  );

  return $form;
}